#ifndef PARSERECORD_H
#define PARSERECORD_H

#include <QObject>
#include <parsesheet.h>

class ParseRecord : public ParseSheet
{
public:
    ParseRecord();
    ~ParseRecord();
public slots:
    void setNextRecord(void);
    void setPrevRecord(void);
    int getColumnCount(int index);
    int getRowCount(int index);
    QStringList getRow(int index, int row);
protected slots:
private:
};

#endif // PARSERECORD_H
