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
    void selectCell(int row, int col);
    void setNextCell();
    void setPrevCell();
protected slots:
    void setCurrentCell(int row, int col);
private:
};

#endif // PARSECELL_H
