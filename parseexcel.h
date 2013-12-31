#ifndef PARSEEXCEL_H
#define PARSEEXCEL_H

#include <QObject>
#include <parsecell.h>

class ParseExcel : public QObject, public ParseCell
{
public:
    explicit ParseExcel(QObject *parent = 0);
    ~ParseExcel();
public slots:
};

#endif // PARSEEXCEL_H
