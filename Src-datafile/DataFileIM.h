#ifndef DATAFILEIM_H
#define DATAFILEIM_H

#include "DataFile.h"

/* ---------------------------------------------------------------- */
/* Types ---------------------------------------------------------- */
/* ---------------------------------------------------------------- */

class DataFileIM : public DataFile
{
private:
    // Input mode
    int imCumTypCnt[CimCfg::imNTypes];

public:
    // ---------
    // Meta data
    // ---------

    int origID2Type( int ic ) const;
    double origID2Gain( int ic ) const;
    ChanMapIM chanMap() const;

protected:
    virtual void subclassParseMetaData();
    virtual void subclassStoreMetaData( const DAQ::Params &p );
    virtual int subclassGetAcqChanCount( const DAQ::Params &p );
    virtual int subclassGetSavChanCount( const DAQ::Params &p );

    virtual void subclassSetSNSChanCounts(
        const DAQ::Params   *p,
        const DataFile      *dfSrc );

    virtual void subclassListSavChans(
        QVector<uint>       &v,
        const DAQ::Params   &p );

private:
    void parseChanCounts();
};

#endif  // DATAFILEIM_H

