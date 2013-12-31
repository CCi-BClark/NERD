#include "navigate.h"
#include <QDebug>

Navigate::Navigate(QWidget *parent) : QWidget(parent){
    excelView = new ExcelMockWidget;
    btnNavigation = new NavigateButtons;
    focusRecord = new SystemFocusWidget;
    parser = new ParseExcel;

    btnHContainer = new QHBoxLayout;
    viewVContainer = new QVBoxLayout;
    QSpacerItem *spacer;
    spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding,QSizePolicy::Minimum);

    btnHContainer->addWidget(btnNavigation);
    btnHContainer->addSpacerItem(spacer);
    btnHContainer->addWidget(focusRecord);

    viewVContainer->addWidget(excelView);
    viewVContainer->addItem(btnHContainer);

    setLayout(viewVContainer);
    setSignalSlot();
}

Navigate::~Navigate(){
    delete excelView;
    delete focusRecord;
    delete btnNavigation;
}

void Navigate::setDataFile(QFileInfo file){
    int rows;
    int columns;
    parser->setData(file);
    int count = parser->getSheetCount();
    for (int i = 0; i < count; ++i) {
        parser->setCurrentWorksheet(i);
        rows = parser->getRowCount()-1;
        columns = parser->getColumnCount();
        excelView->setSheetProperties(rows,columns,parser->getRow(1));
        for (int r = 1; r <= rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                excelView->addCell(r,c,parser->getCell(r+1,c+1));
            }
        }
        excelView->addSheet(i,parser->getSheetTitle(i));
    }
    parser->setCurrentWorksheet(0);
    focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

QString Navigate::getDataFileName(){
    return parser->getFileTitle();
}

void Navigate::sheetIndexChanged(int index){
    parser->setCurrentWorksheet(index);
}

void Navigate::setNextCell(){
    int prevRow = parser->getCurrentRow();
    parser->setNextCell();
    int currentRow = parser->getCurrentRow();
    int totalRow = parser->getRowCount()-1;
    int currentColumn = parser->getCurrentColumn();
    int totalColumn = parser->getColumnCount() - 1;
    if(totalRow == currentRow){
        if (totalColumn == currentColumn) {
            btnNavigation->setNextToggle(0);
        } else {
            btnNavigation->setNextToggle(1);
        }
    } else {
        if (1 == currentRow) {
            btnNavigation->setPrevToggle(1);
        } else {
            btnNavigation->setPrevToggle(2);
        }
    }
    if (prevRow < currentRow) {
        focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    }
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setNextRecord(){
    parser->setNextRecord();
    int currentRow = parser->getCurrentRow();
    int totalRow = parser->getRowCount()-1;
    if(totalRow == currentRow){
        btnNavigation->setNextToggle(1);
        if (1 == currentRow) {
            btnNavigation->setPrevToggle(1);
        } else {
            btnNavigation->setPrevToggle(2);
        }
    } else {
        btnNavigation->setNextToggle(2);
        btnNavigation->setPrevToggle(2);
    }
    focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setPrevCell(){
    int prevRow = parser->getCurrentRow();
    parser->setPrevCell();
    int currentColumn = parser->getCurrentColumn();
    int totalRow = parser->getRowCount()-1;
    int currentRow = parser->getCurrentRow();
    if(1 == currentRow){
        if (0 == currentColumn) {
            btnNavigation->setPrevToggle(0);
        } else {
            btnNavigation->setPrevToggle(1);
        }
        if (totalRow == currentRow) {
            btnNavigation->setNextToggle(1);
        } else {
            btnNavigation->setNextToggle(2);
        }
    } else {
        btnNavigation->setPrevToggle(2);
        if (totalRow == currentRow) {
            btnNavigation->setNextToggle(1);
        } else {
            btnNavigation->setNextToggle(2);
        }
    }
    if (prevRow > currentRow) {
        focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    }
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setPrevRecord(){
    parser->setPrevRecord();
    int currentRow = parser->getCurrentRow();
    if(1 == currentRow){
        int totalRow = parser->getRowCount()-1;
        btnNavigation->setPrevToggle(0);
        if (totalRow == currentRow) {
            btnNavigation->setNextToggle(1);
        } else {
            btnNavigation->setNextToggle(2);
        }
    } else {
        btnNavigation->setPrevToggle(2);
        btnNavigation->setNextToggle(2);
    }
    focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setSignalSlot(){
    connect(btnNavigation,SIGNAL(clickedNextCell()),this,SLOT(setNextCell()));
    connect(btnNavigation,SIGNAL(clickedNextRecord()),this,SLOT(setNextRecord()));
    connect(btnNavigation,SIGNAL(clickedPrevCell()),this,SLOT(setPrevCell()));
    connect(btnNavigation,SIGNAL(clickedPrevRecord()),this,SLOT(setPrevRecord()));
    connect(focusRecord,SIGNAL(hotkey(int)),this,SLOT(hotkeyPressed(int)));
    connect(excelView, SIGNAL(indexChanged(int)),this,SLOT(sheetIndexChanged(int)));
}

void Navigate::hotkeyPressed(int key){
    switch (key) {
    case 200:
        setNextCell();
        break;
    case 300:
        setNextRecord();
        break;
    case 400:
        setPrevCell();
        break;
    case 500:
        setPrevRecord();
        break;
    default:
        break;
    }
}
