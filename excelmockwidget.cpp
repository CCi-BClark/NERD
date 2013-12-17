#include "excelmockwidget.h"

ExcelMockWidget::ExcelMockWidget(QWidget *parent) : QWidget(parent) {
    book = new Wbook;
    QVBoxLayout *container;
    container = new QVBoxLayout;
    container->addWidget(book);
    setLayout(container);
}

ExcelMockWidget::~ExcelMockWidget(){
}

void ExcelMockWidget::addCell(int row, int column, QVariant cell){
    sheet->setCell(row,column,cell);
}

void ExcelMockWidget::addSheet(int index, QString title){
    book->createTab(index, title, sheet);
    //delete sheet;
}

void ExcelMockWidget::setSheetProperties(int rows, int columns, QStringList headers){
    sheet = new Ssheet;
    sheet->setSheetColumnSpan(columns);
    sheet->setSheetRowSpan(rows);
    sheet->setSheetHeaders(headers);
}
