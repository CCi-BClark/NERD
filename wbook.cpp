#include "wbook.h"
#include "ui_wbook.h"

Wbook::Wbook(QWidget *parent) : QWidget(parent), ui(new Ui::Wbook){
    ui->setupUi(this);
    file = new ParseBook;

}

Wbook::~Wbook(){
    delete ui;
}

QString Wbook::getFileName(){
    return file->getFileTitle();
}

void Wbook::setData(QFileInfo info){
    file->setData(info);
    createTabs();
}

void Wbook::createTabs(void){
    for(int i = 0;i < file->getSheetCount();i++){
        Ssheet *sheet;
        sheet = new Ssheet;
        sheet->setWidget(file->getSheet(i));
        ui->tabWidget->insertTab(i,sheet,file->getSheet(i).getTitle());
    }
}
