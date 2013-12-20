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
    int getColumnCount(void);
    int getCurrentRow(void);
    int getRowCount(void);
    QStringList getRecord(int row);
    QStringList getRow(int index, int row);
protected slots:
private:
    int rowPos;
};

#endif // PARSERECORD_H
