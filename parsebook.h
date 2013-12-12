#ifndef PARSEBOOK_H
#define PARSEBOOK_H

#include <QObject>
#include <QFileDialog>
#include <QFileInfo>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"
#include <vector>
#include "parsesheet.h"

class ParseBook
{
public:
    ParseBook();
    ~ParseBook();

    int getSheetCount(void);
    void setData(QFileInfo open);
    ParseSheet getSheet(int i);

protected:
    void createSheets(void);

private:
    std::vector<ParseSheet> sheets;
    QXlsx::Document *dataStore;
    QXlsx::CellRange *range;
    QFileInfo file;
};

#endif // PARSEBOOK_H
