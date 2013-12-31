#include "navigatebuttons.h"
#include "ui_navigatebuttons.h"

NavigateButtons::NavigateButtons(QWidget *parent) : QWidget(parent), ui(new Ui::NavigateButtons){
    ui->setupUi(this);
    connect(ui->btnNext,SIGNAL(clicked()),this,SLOT(clickNextRecord()));
    connect(ui->btnPrev,SIGNAL(clicked()),this,SLOT(clickPrevRecord()));
    connect(ui->btnNextCell,SIGNAL(clicked()),this,SLOT(clickNextCell()));
    connect(ui->btnPrevCell,SIGNAL(clicked()),this,SLOT(clickPrevCell()));
}

NavigateButtons::~NavigateButtons(){
    delete ui;
}

void NavigateButtons::setNextToggle(int toggle){
    switch (toggle) {
    case 0:
        setNextCellEnabled(false);
        setNextEnabled(false);
        break;
    case 1:
        setNextCellEnabled(true);
        setNextEnabled(false);
        break;
    case 2:
        setNextCellEnabled(true);
        setNextEnabled(true);
        break;
    default:
        break;
    }
}

void NavigateButtons::setPrevToggle(int toggle){
    switch (toggle) {
    case 0:
        setPrevCellEnabled(false);
        setPrevEnabled(false);
        break;
    case 1:
        setPrevCellEnabled(true);
        setPrevEnabled(false);
        break;
    case 2:
        setPrevCellEnabled(true);
        setPrevEnabled(true);
        break;
    default:
        break;
    }
}

void NavigateButtons::setNextEnabled(bool tf){
    ui->btnNext->setEnabled(tf);
}

void NavigateButtons::setNextCellEnabled(bool tf){
    ui->btnNextCell->setEnabled(tf);
}

void NavigateButtons::setPrevEnabled(bool tf){
    ui->btnPrev->setEnabled(tf);
}

void NavigateButtons::setPrevCellEnabled(bool tf){
    ui->btnPrevCell->setEnabled(tf);
}

void NavigateButtons::clickNextRecord(){
    emit clickedNextRecord();
}

void NavigateButtons::clickNextCell(){
    emit clickedNextCell();
}

void NavigateButtons::clickPrevRecord(){
    emit clickedPrevRecord();
}

void NavigateButtons::clickPrevCell(){
    emit clickedPrevCell();
}
