#include "wbook.h"
#include "ui_wbook.h"

Wbook::Wbook(QWidget *parent) : QWidget(parent), ui(new Ui::Wbook){
    ui->setupUi(this);
    file = new ParseBook;
}

Wbook::~Wbook(){
    delete ui;
}

void Wbook::setData(QFileInfo info){
    file->setData(info);
}

void Wbook::createTabs(void){
    for(int i = 0;i < file->getSheetCount();i++){
        //ui->tabWidget->insertTab(i,file->getSheet(i),);
    }
}

void Wbook::createTab(QString title){

}
