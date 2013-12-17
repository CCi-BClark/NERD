#include "navigate.h"

Navigate::Navigate(QWidget *parent) : QWidget(parent){
    excelView = new ExcelMockWidget;
    btnNavigation = new NavigateButtons;
    btnControlState = new SystemFocusWidget;
    parser = new ParseExcel;

    btnHContainer = new QHBoxLayout;
    viewVContainer = new QVBoxLayout;
    QSpacerItem *spacer;
    spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding,QSizePolicy::Minimum);

    btnHContainer->addWidget(btnNavigation);
    btnHContainer->addSpacerItem(spacer);
    btnHContainer->addWidget(btnControlState);

    viewVContainer->addWidget(excelView);
    viewVContainer->addItem(btnHContainer);

    setLayout(viewVContainer);
    setSignalSlot();
}

Navigate::~Navigate(){
    delete excelView;
    delete btnControlState;
    delete btnNavigation;
}

void Navigate::setDataFile(QFileInfo file){
    int rows;
    int columns;
    parser->setData(file);
    int count = parser->getSheetCount();
    for (int i = 0; i < count; ++i) {
        parser->setCurrentWorksheet(i);
        rows = parser->getRowCount(i);
        columns = parser->getColumnCount(i);
        excelView->setSheetProperties(rows-1,columns,parser->getRow(i,1));
        for (int r = 1; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                excelView->addCell(r,c,parser->getCell(r+1,c+1));
            }
        }
        excelView->addSheet(i,parser->getSheetTitle(i));
    }
}

void Navigate::setNextCell(){
    parser->setNextCell();
}

void Navigate::setNextRecord(){
    parser->setNextRecord();
}

void Navigate::setPrevCell(){
    parser->setPrevCell();
}

void Navigate::setPrevRecord(){
    parser->setPrevRecord();
}

void Navigate::setSignalSlot(){
    connect(btnNavigation,SIGNAL(clickedNextCell()),this,SLOT(setNextCell()));
    connect(btnNavigation,SIGNAL(clickedNextRecord()),this,SLOT(setNextRecord()));
    connect(btnNavigation,SIGNAL(clickedPrevCell()),this,SLOT(setPrevCell()));
    connect(btnNavigation,SIGNAL(clickedPrevRecord()),this,SLOT(setPrevRecord()));
    connect(btnControlState,SIGNAL(hotkey(int)),this,SLOT(hotkeyPressed(int)));
}

void Navigate::hotkeyPressed(int key){
    switch (key) {
    case 200:
        setNextRecord();
        break;
    case 300:
        setNextCell();
        break;
    case 400:
        setPrevRecord();
        break;
    case 500:
        setPrevCell();
        break;
    default:
        break;
    }
}
