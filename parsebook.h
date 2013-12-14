#ifndef PARSEBOOK_H
#define PARSEBOOK_H

#include <QObject>
#include <QFileDialog>
#include <QFileInfo>
#include "xlsxdocument.h"
#include "xlsxconditionalformatting.h"
#include "xlsxglobal.h"
#include "xlsxrichstring.h"
#include "xlsxworksheet.h"
#include "xlsxworkbook.h"
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
    QString getFileTitle(void);
protected:
    void createSheets(void);

private:
    ParseSheet *sheet;
    std::vector<ParseSheet> sheets;
    QXlsx::Document *dataStore;
    QXlsx::CellRange *range;
    QFileInfo file;
};

#endif // PARSEBOOK_H
