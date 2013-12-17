#include "wbook.h"
#include "ui_wbook.h"

Wbook::Wbook(QWidget *parent) : QWidget(parent), ui(new Ui::Wbook){
    ui->setupUi(this);
}

Wbook::~Wbook(){
    delete ui;
}

void Wbook::createTab(int index, QString title, QWidget *worksheet){
    ui->tabWidget->insertTab(index, worksheet, title);
}

