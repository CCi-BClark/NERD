#ifndef PARSESHEET_H
#define PARSESHEET_H

#include <QObject>
#include <xlsxworksheet.h>
#include <parsebook.h>

class ParseSheet : public ParseBook
{
public:
    ParseSheet();
    ~ParseSheet();
    void setNextSheet(void);
    void setPrevSheet(void);
    int sheetIndex(void);
public slots:

protected slots:
private:
    int sheetPos;
};

#endif // PARSESHEET_H
