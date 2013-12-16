#include "navigatebuttons.h"
#include "ui_navigatebuttons.h"

NavigateButtons::NavigateButtons(QWidget *parent) : QWidget(parent), ui(new Ui::NavigateButtons){
    ui->setupUi(this);
}

NavigateButtons::~NavigateButtons(){
    delete ui;
}

void NavigateButtons::clickNextRecord(){
    emit clickedNextRecord();
}

void NavigateButtons::clickNextCell(){
    emit clickedNextCell();
}

void NavigateButtons::clickPrevRecord(){
    emit clickPrevRecord();
}

void NavigateButtons::clickPrevCell(){
    emit clickPrevCell();
}
