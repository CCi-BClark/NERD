#ifndef PARSERECORD_H
#define PARSERECORD_H

#include <QObject>

class ParseRecord
{
public:
    ParseRecord();
    ~ParseRecord();
public slots:
    void selectRecord(int row);
    void setNextRecord();
    void setPrevRecord();
    void getRecordCount(void);
protected slots:
    void setCurrentRecord(int row);
};

#endif // PARSERECORD_H
