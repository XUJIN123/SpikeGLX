#ifndef GRAPHFETCHER_H
#define GRAPHFETCHER_H

#include <QObject>
#include <QMutex>

class GraphsWindow;
class AIQ;

class QThread;

/* ---------------------------------------------------------------- */
/* Types ---------------------------------------------------------- */
/* ---------------------------------------------------------------- */

class GFWorker : public QObject
{
    Q_OBJECT

private:
    struct Stream {
        const AIQ   *aiQ;
        quint64     nextCt;
        Stream( const AIQ *aiQ ) : aiQ(aiQ), nextCt(0) {}
    };

private:
    GraphsWindow    *gw;
    Stream          imS,
                    niS;
    mutable QMutex  runMtx;
    volatile bool   paused,
                    pleaseStop;

public:
    GFWorker( GraphsWindow *gw, const AIQ *imQ, const AIQ *niQ )
    :   QObject(0), gw(gw),
        imS(imQ), niS(niQ),
        paused(false), pleaseStop(false)    {}
    virtual ~GFWorker()                     {}

    void pause( bool pause ) {QMutexLocker ml( &runMtx ); paused = pause;}
    void stop()             {QMutexLocker ml( &runMtx ); pleaseStop = true;}
    bool isPaused() const   {QMutexLocker ml( &runMtx ); return paused;}
    bool isStopped() const  {QMutexLocker ml( &runMtx ); return pleaseStop;}

signals:
    void finished();

public slots:
    void run();

private:
    void fetch( Stream &S, double loopT, double oldestSecs );
};


class GraphFetcher
{
private:
    QThread     *thread;
    GFWorker    *worker;

public:
    GraphFetcher(
    GraphsWindow    *gw,
    const AIQ       *imQ,
    const AIQ       *niQ );
    virtual ~GraphFetcher();

    void pause( bool pause )    {worker->pause( pause );}
};

#endif  // GRAPHFETCHER_H


