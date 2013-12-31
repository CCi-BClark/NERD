#ifndef PARSEBOOK_H
#define PARSEBOOK_H

#include <QObject>
#include <QWidget>
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

class ParseBook
{
public:
    ParseBook();
    ~ParseBook();

    int getSheetCount(void);
    void setData(QFileInfo open);
    void setCurrentWorksheet(int index);
    QString getFileTitle(void);
    QString getSheetTitle(int index);
protected:
    QXlsx::Document *dataStore;

private:
    QXlsx::CellRange *range;
    QFileInfo file;
};

#endif // PARSEBOOK_H
