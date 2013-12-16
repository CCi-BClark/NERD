#include "wbook.h"
#include "ui_wbook.h"

Wbook::Wbook(QWidget *parent) : QWidget(parent), ui(new Ui::Wbook){
    ui->setupUi(this);
}

Wbook::~Wbook(){
    delete ui;
}

void Wbook::createBook(){
    createTabs();
}

void Wbook::createTabs(void){
    /*
    for(int i = 0;i < file->getSheetCount();i++){
        Ssheet *sheet;
        sheet = new Ssheet;
        sheet->setSheet();
        ui->tabWidget->insertTab(i,sheet,"");
    }
    */
}
