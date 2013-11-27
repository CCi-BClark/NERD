#ifndef RECORDWINDOW_H
#define RECORDWINDOW_H

#include <QDialog>
#include <QClipboard>
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"

namespace Ui {
class RecordWindow;
}

class RecordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RecordWindow(QWidget *parent = 0);
    ~RecordWindow();

    int getRecordNum(void);
    int getColumnNum(void);

public slots:
    void setRecords(QXlsx::Document *&file);
    void setRecordNum(int rec);
    void setRecordTotal(void);
    void setRecordDisplay(void);
    void setDataItem(int item);

protected:
    void setClipBoard(void);

protected slots:

private slots:

private:
    Ui::RecordWindow *ui;
    QXlsx::Document *dataStore;
    QClipboard *clipboard;
    int currentR;
    int currentC;
    int total;
};

#endif // RECORDWINDOW_H
