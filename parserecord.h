#ifndef PARSERECORD_H
#define PARSERECORD_H

#include <QObject>
#include <QDateTime>
#include <parsesheet.h>

class ParseRecord : public ParseSheet
{
public:
    ParseRecord();
    ~ParseRecord();
public slots:
    void setNextRecord(void);
    void setPrevRecord(void);
    int getColumnCount(void);
    int getCurrentRow(void);
    int getRowCount(void);
    QStringList getRow(int row);
protected slots:
private:
    int rowPos;
};

#endif // PARSERECORD_H
