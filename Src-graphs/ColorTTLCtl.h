#ifndef COLORTTLCTL_H
#define COLORTTLCTL_H

#include "SGLTypes.h"

#include <QObject>
#include <QMutex>
#include <QString>
#include <QVector>

namespace DAQ {
struct Params;
}

namespace Ui {
class ColorTTLDialog;
}

class HelpButDialog;
class MGraphX;

class QLabel;
class QGroupBox;
class QComboBox;
class QSpinBox;
class QDoubleSpinBox;

/* ---------------------------------------------------------------- */
/* Types ---------------------------------------------------------- */
/* ---------------------------------------------------------------- */

class ColorTTLCtl : public QObject
{
    Q_OBJECT

private:
    struct TTLClr {
        double      T;
        QString     stream;
        int         chan,
                    bit;
        bool        isAnalog,
                    isOn;

        bool validIm(
            QString             &err,
            const QString       &clr,
            const DAQ::Params   &p );
        bool validNi(
            QString             &err,
            const QString       &clr,
            const DAQ::Params   &p );
        bool valid(
            QString             &err,
            const QString       &clr,
            const DAQ::Params   &p );
    };

    struct ColorTTLSet {
        TTLClr      clr[4];
        double      minSecs;
        int         inarow;
    };

    struct ChanGroup {
        QGroupBox       *GB;
        QComboBox       *stream;
        QComboBox       *analog;
        QSpinBox        *chan;
        QLabel          *TLbl;
        QDoubleSpinBox  *T;

        void analogChanged( TTLClr &C, bool algCBChanged );
    };

private:
    const DAQ::Params   &p;
    HelpButDialog       *dlg;
    Ui::ColorTTLDialog  *cttlUI;
    MGraphX             *Xim,
                        *Xni;
    ChanGroup           grp[4];
    ColorTTLSet         set,
                        uiSet;
    mutable QMutex      setMtx;
    int                 state[4];   // {0,1}=seek{high,low}

public:
    ColorTTLCtl(
        QObject             *parent,
        MGraphX             *Xim,
        MGraphX             *Xni,
        const DAQ::Params   &p );
    virtual ~ColorTTLCtl();

    void showDialog();

    void scanBlock(
        const vec_i16   &data,
        quint64         headCt,
        int             nC,
        bool            isImec );

private slots:
    void C0GBClicked();
    void C1GBClicked();
    void C2GBClicked();
    void C3GBClicked();
    void ana0CBChanged();
    void ana1CBChanged();
    void ana2CBChanged();
    void ana3CBChanged();
    void okBut();

private:
    bool valid( QString &err );

    void loadSettings();
    void saveSettings() const;

    void resetState();

    int anyEvents( QVector<int> &clr, bool isImec ) const;

    bool getChan(
        int     &chan,
        int     &bit,
        int     &thresh,
        int     clr,
        bool    isImec ) const;

    bool findRisingEdge(
        int         &outCt,
        const short *data,
        int         ntpts,
        int         offset,
        int         nchans,
        int         chan,
        qint16      T ) const;

    bool findBitRisingEdge(
        int         &outCt,
        const short *data,
        int         ntpts,
        int         offset,
        int         nchans,
        int         chan,
        int         bit ) const;

    bool findFallingEdge(
        int         &outCt,
        const short *data,
        int         ntpts,
        int         offset,
        int         nchans,
        int         chan,
        qint16      T ) const;

    bool findBitFallingEdge(
        int         &outCt,
        const short *data,
        int         ntpts,
        int         offset,
        int         nchans,
        int         chan,
        int         bit ) const;

    void processEvents(
        const vec_i16   &data,
        quint64         headCt,
        int             nC,
        QVector<int>    &vClr,
        bool            isImec );
};

#endif  // COLORTTLCTL_H


