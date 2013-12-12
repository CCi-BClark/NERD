#ifndef PARSESHEET_H
#define PARSESHEET_H

#include <QObject>

class ParseSheet
{
public:
    ParseSheet();
    ~ParseSheet();
public slots:
    void selectSheet(int row);
    void setNextSheet();
    void setPrevSheet();
    void getCurrentRow(void);
    void getCurrentColumn(void);
protected slots:
    void setCurrentSheet(int row);
private:
    int currentR;
    int currentC;
};

#endif // PARSESHEET_H
