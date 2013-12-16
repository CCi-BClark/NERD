#include "navigate.h"

Navigate::Navigate(QWidget *parent) : QWidget(parent){
    excelView = new ExcelMockWidget;
    btnNavigation = new NavigateButtons;
    btnControlState = new SystemFocusWidget;
    parser = new ParseExcel;

    btnHContainer = new QHBoxLayout;
    viewVContainer = new QVBoxLayout;

    btnHContainer->addWidget(btnNavigation);
    btnHContainer->addWidget(btnControlState);

    viewVContainer->addWidget(excelView);
    //viewVContainer->addWidget(btnHContainer);

    setLayout(viewVContainer);
    setSignalSlot();
}

Navigate::~Navigate(){
    delete excelView;
    delete btnNavigation;
    delete parser;
    delete btnControlState;
    delete btnHContainer;
    delete viewVContainer;
}

void Navigate::setDataFile(QFileInfo file){
    parser->setData(file);
    excelView->createBook();
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
