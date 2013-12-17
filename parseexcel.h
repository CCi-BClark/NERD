#ifndef PARSEEXCEL_H
#define PARSEEXCEL_H

#include <QObject>
#include <parsecell.h>

class ParseExcel : public QObject, public ParseCell
{
    Q_OBJECT
public:
    explicit ParseExcel(QObject *parent = 0);
    ~ParseExcel();
signals:
public slots:
};

#endif // PARSEEXCEL_H
