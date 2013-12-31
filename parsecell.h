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
    int getCurrentColumn(void);
    QVariant getCell(int row, int column);
    void setNextRecord(void);
    void setPrevRecord(void);
protected:
    void resetPosFront(void);
    void resetPosBack(void);
private:
    int columnPos;
};

#endif // PARSECELL_H
