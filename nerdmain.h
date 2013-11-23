#ifndef NERDMAIN_H
#define NERDMAIN_H

#include <QMainWindow>
#include <QFileInfo>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include "aboutwindow.h"
#include "recordwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QShortcut>
#include <QKeySequence>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"

namespace Ui {
class NerdMain;
}

class NerdMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit NerdMain(QWidget *parent = 0);
    ~NerdMain();

public slots:
    void setFileLabel(QString label);// Set "File In Progress" label.
    void setFile(void);             // Set QXlsx data type.
    void setTable(void);            // Set table data.

protected:

protected slots:
    void open(void);                // Process open file request.
    void start(void);               // Process start navigation request.
    void toggleDataElem(bool isData);// Hide/show data table.
    void toggleStartStop();         // Start/stop data navigation.
    void setCurrentRecord(int row); // Set current record.
    void setCurrentCell(int row, int col);// Set current cell.
    void setNextRecord();           // Goto next record.
    void setPrevRecord();           // Goto previous record.
    void setNextCell(void);         // Goto next cell(tab key)
    void setPrevCell(void);         // Goto previous cell(Ctrl+Tab)

private slots:
    void about(void);               // Show about window.
    void openHomepage(void);        // Open CCi homepage.

private:
    Ui::NerdMain *ui;
    RecordWindow *winRecord;
    QFileInfo fileInfo;
    QXlsx::Document *dataStore;
    QXlsx::CellRange *range;
};

#endif // NERDMAIN_H
