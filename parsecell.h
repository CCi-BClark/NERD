#ifndef PARSECELL_H
#define PARSECELL_H

#include <QObject>
#include <parserecord.h>

class ParseCell : public ParseRecord
{
public:
    ParseCell();
    ~ParseCell();
public slots:
    void setNextCell(void);
    void setPrevCell(void);
    int getCurrentRow(void);
    int getCurrentColumn(void);
    QVariant getCell(int row, int column);
protected slots:
private:
    int rowPos;
    int columnPos;
};

#endif // PARSECELL_H
