#ifndef EXCELMOCKWIDGET_H
#define EXCELMOCKWIDGET_H

#include <wbook.h>
#include <ssheet.h>
#include <QWidget>
#include <QLayout>

class ExcelMockWidget : public QWidget{
    Q_OBJECT
public:
    explicit ExcelMockWidget(QWidget *parent = 0);
    ~ExcelMockWidget();
    void addCell(int row, int column, QVariant cell);
    void addSheet(int index, QString title);
    void setSheetProperties(int rows, int columns, QStringList headers);
signals:

public slots:

private:
    Wbook *book;
    Ssheet *sheet;
};

#endif // EXCELMOCKWIDGET_H
