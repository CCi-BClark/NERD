#ifndef PARSEEXCEL_H
#define PARSEEXCEL_H

#include <QObject>
#include <parsecell.h>

class ParseExcel : public QObject, public ParseCell
{
    Q_OBJECT
public:
    explicit ParseExcel(QObject *parent = 0);

    ParseRecord getRecord(void);
    ParseRecord getRecordAt(int row);
    ParseCell getCell(void);
    ParseCell getCellAt(int row, int column);
signals:

public slots:
};

#endif // PARSEEXCEL_H
