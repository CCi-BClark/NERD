#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <QApplication>
#include <QWidget>
#include <QFileDialog>
#include <QFileInfo>
#include <QClipboard>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"
#include <qsystemhotkey.h>

class ParseFile
{
public:
    ParseFile();
    ~ParseFile();
    void setFile(QFileInfo open);
    void getRecordCount(void);

private:
    QXlsx::Document *dataStore;
    QClipboard *clipboard;
    QXlsx::CellRange *range;
    QFileInfo file;
};

#endif // PARSEFILE_H
