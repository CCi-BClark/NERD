#ifndef EXCELVIEW_H
#define EXCELVIEW_H

#include <wbook.h>
#include <ssheet.h>
#include <QWidget>
#include <QLayout>

class ExcelView : public QWidget
{
    Q_OBJECT
public:
    ExcelView(QWidget *parent = 0);
    ~ExcelView();
    void addCell(int row, int column, QVariant cell);
    void addSheet(int index, QString title);
    void setSheetProperties(int rows, int columns, QStringList headers);

signals:
    void indexChanged(int);

public slots:
    void emitIndexChange(int index);
    void select(int row, int column);

private:
    Wbook *book;
    Ssheet *sheet;
};

#endif // EXCELVIEW_H
