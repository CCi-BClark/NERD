#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QWidget>
#include "xlsxdocument.h"

namespace Ui {
class Spreadsheet;
}

class Spreadsheet : public QWidget
{
    Q_OBJECT

public:
    explicit Spreadsheet(QWidget *parent = 0);
    ~Spreadsheet();

    void setTable(QXlsx::Document *&file);

public slots:
    // Record Navigation
    void setCurrentRecord(int row); // Set current record.
    void setCurrentCell(int row, int col);// Set current cell.
    void setNextRecord();           // Goto next record.
    void setPrevRecord();           // Goto previous record.
    void setNextCell(void);         // Goto next cell(tab key)
    void setPrevCell(void);         // Goto previous cell(Ctrl+Tab)

private:
    Ui::Spreadsheet *ui;
    QXlsx::Document *dataStore;
    QXlsx::CellRange *range;
};

#endif // SPREADSHEET_H
