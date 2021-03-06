
#include "ui_AOWindow.h"

#include "AOCtl.h"
#include "Util.h"
#include "MainApp.h"
#include "ConfigCtl.h"
#include "Run.h"
#include "HelpWindow.h"
#include "CniAODmx.h"
#include "CniAOSim.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QSettings>

using namespace DAQ;

/* ---------------------------------------------------------------- */
/* User ----------------------------------------------------------- */
/* ---------------------------------------------------------------- */

// Given a validated channel string, rewite it in cannonical form.
//
void AOCtl::User::prettyChanStr()
{
    QTextStream ts( &uiChanStr, QIODevice::WriteOnly | QIODevice::Text );
    QStringList pairs = uiChanStr.split( ",", QString::SkipEmptyParts );

    uiChanStr.clear();

    foreach( const QString &pair, pairs ) {

        QStringList ab = pair.split( "=", QString::SkipEmptyParts );

        if( uiChanStr.size() )
            ts << ", ";

        QString ai = ab.last().trimmed();

        if( ai == "t" )
            ai = "T";

        ts << ab.first().trimmed() << "=" << ai;
    }
}


void AOCtl::User::loadSettings( bool remote )
{
    QString file = QString("aoctl%1").arg( remote ? "remote" : "");

    STDSETTINGS( settings, file );
    settings.beginGroup( "AOCtl" );

    range.rmin  = settings.value( "rangeMin", -10.0 ).toDouble();
    range.rmax  = settings.value( "rangeMax", 10.0 ).toDouble();
    devStr      = settings.value( "device", "" ).toString();
    aoClockStr  = settings.value( "clock", "Internal" ).toString();
    uiChanStr   = settings.value( "channels", "0=4" ).toString();
    loCutStr    = settings.value( "loCut", "OFF" ).toString();
    hiCutStr    = settings.value( "hiCut", "INF" ).toString();
    volume      = settings.value( "volume", 1.0 ).toDouble();
    autoStart   = settings.value( "autoStart", false ).toBool();
}


void AOCtl::User::saveSettings( bool remote ) const
{
    QString file = QString("aoctl%1").arg( remote ? "remote" : "");

    STDSETTINGS( settings, file );
    settings.beginGroup( "AOCtl" );

    settings.setValue( "rangeMin", range.rmin );
    settings.setValue( "rangeMax", range.rmax );
    settings.setValue( "device", devStr );
    settings.setValue( "clock", aoClockStr );
    settings.setValue( "channels", uiChanStr );
    settings.setValue( "loCut", loCutStr );
    settings.setValue( "hiCut", hiCutStr );
    settings.setValue( "volume", volume );
    settings.setValue( "autoStart", autoStart );
}

/* ---------------------------------------------------------------- */
/* AOCtl ---------------------------------------------------------- */
/* ---------------------------------------------------------------- */

AOCtl::AOCtl( const DAQ::Params &p, QWidget *parent )
    :   QWidget(parent), p(p),
        noteDlg(0), aoMtx(QMutex::Recursive)
{
#ifdef HAVE_NIDAQmx
    niAO = new CniAODmx( this, p );
#else
    niAO = new CniAOSim( this, p );
#endif

    aoUI = new Ui::AOWindow;
    aoUI->setupUi( this );
    ConnectUI( aoUI->deviceCB, SIGNAL(activated(QString)), this, SLOT(deviceCBChanged()) );
    ConnectUI( aoUI->loCB, SIGNAL(currentIndexChanged(QString)), this, SLOT(loCBChanged(QString)) );
    ConnectUI( aoUI->hiCB, SIGNAL(currentIndexChanged(int)), this, SLOT(liveChange()) );
    ConnectUI( aoUI->volSB, SIGNAL(valueChanged(double)), this, SLOT(liveChange()) );
    ConnectUI( aoUI->noteLink, SIGNAL(linkActivated(QString)), this, SLOT(showNote()) );
    ConnectUI( aoUI->resetBut, SIGNAL(clicked()), this, SLOT(reset()) );
    ConnectUI( aoUI->stopBut, SIGNAL(clicked()), this, SLOT(stop()) );
    ConnectUI( aoUI->applyBut, SIGNAL(clicked()), this, SLOT(apply()) );
}


AOCtl::~AOCtl()
{
    if( niAO ) {
        delete niAO;
        niAO = 0;
    }

    if( noteDlg ) {
        delete noteDlg;
        noteDlg = 0;
    }

    if( aoUI ) {
        delete aoUI;
        aoUI = 0;
    }
}

/* ---------------------------------------------------------------- */
/* Public --------------------------------------------------------- */
/* ---------------------------------------------------------------- */

double AOCtl::bufSecs()
{
    return qMax( 0.01, 1.0 / daqAINumFetchesPerSec() );
}


void AOCtl::uniqueAIs( QVector<int> &vAI )
{
    vAI.clear();

    if( !mainApp()->getRun()->isAOFetcher() )
        return;

    aoMtx.lock();

        QSet<int>   unique;

        foreach( int ai, o2iMap.values() )
            unique.insert( ai );

        foreach( int ai, unique.values() )
            vAI.push_back( ai );

    aoMtx.unlock();
}


bool AOCtl::showDialog( QWidget *parent )
{
    if( CniCfg::isHardware() )
        CniCfg::probeAOHardware();

    if( !CniCfg::aoDevRanges.size() ) {

        QMessageBox::critical(
            parent,
            "NIDAQ Setup Error",
            "No NIDAQ analog output devices installed.\n\n"
            "Resolve issues in NI 'Measurement & Automation Explorer'." );

        return false;
    }

    if( !mainApp()->getRun()->isAOFetcher() )
        reset();

    show();

    return true;
}


// Signal restart of AO.
//
void AOCtl::restart()
{
    static double   tLast = 0;

    double  t = getTime();

    if( t - tLast < 1.0 )
        return;

    Run *run = mainApp()->getRun();

    if( !run->isRunning() )
        return;

    tLast = t;

    QMetaObject::invokeMethod( run, "aoStart", Qt::QueuedConnection );
}

/* ---------------------------------------------------------------- */
/* Slots ---------------------------------------------------------- */
/* ---------------------------------------------------------------- */

// Return QString::null or error string.
// Used for remote SETAOPARAMS command.
//
QString AOCtl::cmdSrvSetsAOParamStr( const QString &str )
{
// ----------
// Supported?
// ----------

    if( !CniCfg::aoDevRanges.size() )
        return "AO devices not currently installed.";

// -------------------------
// Save settings to own file
// -------------------------

// start with current set

    usr.saveSettings( true );

// overwrite remote subset

    str2RemoteIni( str );

// -----------------------
// Transfer them to dialog
// -----------------------

    reset( true );

// --------------------------
// Remote-specific validation
// --------------------------

// With a dialog, user is constrained to choose items
// we've put into CB controls. Remote case lacks that
// constraint, so we check existence of CB items here.

    if( !aoUI->deviceCB->count()
        || aoUI->deviceCB->currentIndex() < 0
        || usr.devStr != devNames[aoUI->deviceCB->currentIndex()] ) {

        return QString("Device [%1] does not support AO.")
                .arg( usr.devStr );
    }

    if( usr.aoClockStr != aoUI->clockCB->currentText() ) {

        return QString("Clock [%1] not supported on device [%2].")
                .arg( usr.aoClockStr )
                .arg( usr.devStr );
    }

    QString rng = QString("[%1, %2]")
                    .arg( usr.range.rmin )
                    .arg( usr.range.rmax );

    if( rng != aoUI->rangeCB->currentText() ) {

        return QString("Range %1 not supported on device [%2].")
                .arg( rng )
                .arg( usr.devStr );
    }

    if( usr.loCutStr != aoUI->loCB->currentText() ) {

        return QString("Low filter cutoff [%1] not supported.")
                .arg( usr.loCutStr );
    }

    if( usr.hiCutStr != aoUI->loCB->currentText() ) {

        return QString("High filter cutoff [%1] not supported.")
                .arg( usr.hiCutStr );
    }

// -------------------
// Standard validation
// -------------------

    QString err;

    if( !valid( err ) )
        err = QString("AO Parameter Error [%1]").arg( err );

    return err;
}


// Clock and range depend upon device selection.
//
void AOCtl::deviceCBChanged()
{
    int devSel  = aoUI->deviceCB->currentIndex();

    if( !aoUI->deviceCB->count() || devSel < 0 )
        return;

    const QString   &devStr = devNames[devSel];

// ----------------
// PFI (clock line)
// ----------------

    {
        QStringList pfiStrL = CniCfg::getPFIChans( devStr );
        int         npfi    = pfiStrL.count(),
                    pfiSel  = 0;

        aoUI->clockCB->clear();
        aoUI->clockCB->addItem( "Internal" );

        // Note on QString::section() params:
        //
        // ("/dev/PFI").section('/',-1,-1)
        // -> ('/'=sep, -1=last field on right, -1=to end)
        // -> "PFI"

        for( int i = 0; i < npfi; ++i ) {

            QString s = pfiStrL[i].section( '/', -1, -1 );

            aoUI->clockCB->addItem( s );

            if( s == usr.aoClockStr )
                pfiSel = i + 1;
        }

        aoUI->clockCB->setCurrentIndex( pfiSel );
    }

// -----
// Range
// -----

    {
        QComboBox       *CB     = aoUI->rangeCB;
        QString         rngCur;
        QList<VRange>   rngL    = CniCfg::aoDevRanges.values( devStr );
        int             nL      = rngL.size(),
                        sel     = 0;

        // If rangeCB is non-empty, that is, if user has ever
        // seen it before, then we will reselect the current
        // choice. Otherwise, we'll try to select last saved.

        if( CB->count() )
            rngCur = CB->currentText();
        else {
            rngCur = QString("[%1, %2]")
                        .arg( usr.range.rmin )
                        .arg( usr.range.rmax );
        }

        CB->clear();

        for( int i = 0; i < nL; ++i ) {

            const VRange    &r  = rngL[i];
            QString         s   = QString("[%1, %2]")
                                    .arg( r.rmin )
                                    .arg( r.rmax );

            if( s == rngCur )
                sel = i;

            CB->insertItem( i, s );
        }

        CB->setCurrentIndex( sel );
    }
}


void AOCtl::loCBChanged( const QString &str )
{
    aoUI->hiCB->setEnabled( str != "OFF" );

    liveChange();
}


void AOCtl::liveChange()
{
    if( mainApp()->getRun()->isRunning() )
        apply();
}


void AOCtl::showNote()
{
    if( !noteDlg ) {

        noteDlg = new HelpWindow(
                        "AO Wiring Notes",
                        "CommonResources/AO_Wiring.html",
                        this );
    }

    noteDlg->show();
    noteDlg->activateWindow();
}


void AOCtl::reset( bool remote )
{
    if( mainApp()->isInitialized() )
        stop();

    niAO->clearDerived();
    o2iMap.clear();

// ---------
// Get state
// ---------

    aoMtx.lock();
    usr.loadSettings( remote );
    aoMtx.unlock();

// -------
// Devices
// -------

    devNames.clear();
    aoUI->deviceCB->clear();

    QStringList devs    = CniCfg::aoDevChanCount.uniqueKeys();
    int         sel     = 0;

    foreach( const QString &D, devs ) {

        aoUI->deviceCB->addItem(
            QString("%1 (%2)")
            .arg( D )
            .arg( CniCfg::getProductName( D ) ) );

        devNames.push_back( D );

        if( D == usr.devStr )
            sel = aoUI->deviceCB->count() - 1;
    }

    if( aoUI->deviceCB->count() )
        aoUI->deviceCB->setCurrentIndex( sel );

// --------
// Channels
// --------

    aoUI->chansLE->setText( usr.uiChanStr );

// ------
// Checks
// ------

    aoUI->autoChk->setChecked( usr.autoStart );

// ------
// Filter
// ------

// default OFF = first
    sel = aoUI->loCB->findText( usr.loCutStr );
    aoUI->loCB->setCurrentIndex( sel > -1 ? sel : 0 );

// default INF = last
    sel = aoUI->hiCB->findText( usr.hiCutStr );
    aoUI->hiCB->setCurrentIndex( sel > -1 ? sel : aoUI->hiCB->count()-1 );

    aoUI->hiCB->setEnabled( aoUI->loCB->currentIndex() > 0 );

// ------
// Volume
// ------

    aoUI->volSB->setValue( usr.volume );

// --------------------
// Observe dependencies
// --------------------

    deviceCBChanged();
}


void AOCtl::stop()
{
    mainApp()->getRun()->aoStop();
}


void AOCtl::apply()
{
    Run     *run = mainApp()->getRun();
    QString err;

    run->aoStop();

    if( valid( err ) )
        run->aoStart();
    else
        QMessageBox::critical( this, "AO Parameter Error", err );
}

/* ---------------------------------------------------------------- */
/* Protected ------------------------------------------------------ */
/* ---------------------------------------------------------------- */

void AOCtl::keyPressEvent( QKeyEvent *e )
{
    if( e->key() == Qt::Key_Escape ) {

        close();
        e->accept();
    }
    else
        QWidget::keyPressEvent( e );
}


void AOCtl::closeEvent( QCloseEvent *e )
{
    if( noteDlg ) {
        delete noteDlg;
        noteDlg = 0;
    }

    QWidget::closeEvent( e );

    if( e->isAccepted() )
        emit closed( this );
}

/* ---------------------------------------------------------------- */
/* Private -------------------------------------------------------- */
/* ---------------------------------------------------------------- */

void AOCtl::str2RemoteIni( const QString str )
{
    STDSETTINGS( settings, "aoCtlremote" );
    settings.beginGroup( "AOCtl" );

    QTextStream ts( str.toUtf8(), QIODevice::ReadOnly | QIODevice::Text );
    QString     line;

    while( !(line = ts.readLine( 65536 )).isNull() ) {

        int eq = line.indexOf( "=" );

        if( eq > -1 && eq < line.length() ) {

            QString n = line.left( eq ).trimmed(),
                    v = line.mid( eq + 1 ).trimmed();

            settings.setValue( n, v );
        }
    }
}


// Create map<out-chan,in-chan>.
// Observe 'T' = current trigger option.
//
// Return true if format ok.
//
bool AOCtl::str2Map( const QString &s )
{
    o2iMap.clear();

    QStringList pairs = s.split( ",", QString::SkipEmptyParts );
    int         nNeural = p.ni.niCumTypCnt[CniCfg::niSumNeural];

    foreach( const QString &pair, pairs ) {

        QStringList members = pair
                    .trimmed()
                    .split( "=", QString::SkipEmptyParts );

        if( members.count() == 2 ) {

            bool    ok1,
                    ok2;
            uint    ao = members.first().toUInt( &ok1 ),
                    ai = members.last().toUInt( &ok2 );

            if( !ok2 ) {

                if( members.last().contains( QRegExp("\\s*[tT]$") ) ) {

                    int itrg = p.trigChan();

                    // Presume listening only to neural chans

// BK: Temp restrict AO to nidq stream
                    if( p.trigStream() != "nidq" )
                        ai = 0;
                    else if( itrg >= 0 && itrg < nNeural )
                        ai = itrg;
                    else
                        ai = 0;

                    ok2 = true;
                }
            }

            if( !ok1 || !ok2 || o2iMap.contains( ao ) ) {
                o2iMap.clear();
                return false;
            }

            o2iMap.insert( ao, ai );
        }
        else {
            o2iMap.clear();
            return false;
        }
    }

    return !o2iMap.empty();
}


bool AOCtl::valid( QString &err )
{
    if( !mainApp()->cfgCtl()->validated ) {
        err =
            "Run parameters never validated;"
            " do that using Configure dialog.";
        return false;
    }

    if( !CniCfg::aoDevRanges.size() ) {
        err = "NI-Detect never clicked or no AO devices detected.";
        return false;
    }

    QMutexLocker    ml( &aoMtx );

// If never visited dialog before, fill with last known

    if( !devNames.size() )
        reset();

    if( aoUI->deviceCB->currentIndex() < 0 ) {
        err = "No legal device selected.";
        return false;
    }

    QString         devStr  = devNames[aoUI->deviceCB->currentIndex()];
    QList<VRange>   rngL    = CniCfg::aoDevRanges.values( devStr );

    if( !rngL.size() || aoUI->rangeCB->currentIndex() < 0 ) {
        err = QString("Device '%1' is disconnected or off.").arg( devStr );
        return false;
    }

    usr.devStr      = devStr;
    usr.aoClockStr  = aoUI->clockCB->currentText();
    usr.range       = rngL[aoUI->rangeCB->currentIndex()];
    usr.uiChanStr   = aoUI->chansLE->text().trimmed();
    usr.loCutStr    = aoUI->loCB->currentText();
    usr.hiCutStr    = aoUI->hiCB->currentText();
    usr.volume      = aoUI->volSB->value();
    usr.autoStart   = aoUI->autoChk->isChecked();

// Empty chan string?

    if( usr.uiChanStr.isEmpty() ) {
        err = "Channel string empty.";
        return false;
    }

// Valid format?

    if( !str2Map( usr.uiChanStr ) ) {
        err = "Channel string format error.";
        return false;
    }

// Make pretty

    usr.prettyChanStr();
    aoUI->chansLE->setText( usr.uiChanStr );

// AO's legal?

    QVector<uint>   theAOs  = o2iMap.uniqueKeys().toVector();
    int             maxAO   = CniCfg::aoDevChanCount[usr.devStr];

    foreach( int ao, theAOs ) {

        if( ao >= maxAO ) {
            err = QString(
                    "AO channel (%1) exceeds this device's"
                    " channel count (%2).")
                    .arg( ao )
                    .arg( maxAO );
            return false;
        }
    }

// AI's legal?

    uint nAna = p.ni.niCumTypCnt[CniCfg::niSumAnalog];

    foreach( uint ai, o2iMap.values() ) {

        if( ai >= nAna ) {
            err = QString(
                    "AI channel (%1) exceeds AI channel count (%2).")
                    .arg( ai )
                    .arg( nAna );
            return false;
        }
    }

// Good

    usr.saveSettings();
    return true;
}


