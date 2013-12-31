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
        rows = parser->getRowCount();
        columns = parser->getColumnCount();
        excelView->setSheetProperties(rows-1,columns,parser->getRow(i,1));
        for (int r = 1; r < rows; ++r) {
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
    if (parser->getCurrentRow() < parser->getRowCount()-1) {
        if (parser->getCurrentColumn()+1 == parser->getColumnCount()-1) {
            parser->setNextCell();
            if (parser->getCurrentRow() == parser->getRowCount()-1) {
                btnNavigation->setNextCellEnabled(false);
            }
        } else {
            setNextRecord();
        }
    }
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setNextRecord(){
    parser->setNextRecord();
    if (parser->getCurrentRow() >= parser->getRowCount()-1) {
        btnNavigation->setNextEnabled(false);
    }
    if (parser->getCurrentRow() == 2){
        btnNavigation->setPrevEnabled(true);
        btnNavigation->setPrevCellEnabled(true);
    }
    focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setPrevCell(){
    parser->setPrevCell();
    if (parser->getCurrentRow() > 1) {
        if (parser->getCurrentRow() == parser->getRowCount()-1) {
            if (parser->getCurrentColumn() == parser->getColumnCount()-2) {
                btnNavigation->setNextCellEnabled(true);
            }
        }
        focusRecord->setRecord(parser->getRecord(parser->getCurrentRow()));
    } else if (parser->getCurrentRow() == 1) {
        btnNavigation->setPrevEnabled(false);
        if (parser->getCurrentColumn() == 0){
            btnNavigation->setPrevCellEnabled(false);
        }
    }
    qDebug() << "(" << parser->getCurrentRow() << ", " << parser->getCurrentColumn() << ")";
}

void Navigate::setPrevRecord(){
    parser->setPrevRecord();
    if (parser->getCurrentRow() < 2) {
        btnNavigation->setPrevEnabled(false);
        btnNavigation->setPrevCellEnabled(false);
    }
    if (parser->getCurrentRow() < parser->getRowCount()-1) {
        btnNavigation->setNextEnabled(true);
        btnNavigation->setNextCellEnabled(true);
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
