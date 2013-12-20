#include "wbook.h"
#include "ui_wbook.h"

Wbook::Wbook(QWidget *parent) : QWidget(parent), ui(new Ui::Wbook){
    ui->setupUi(this);

    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(emitIndexChange(int)));
}

Wbook::~Wbook(){
    delete ui;
}

void Wbook::createTab(int index, QString title, QWidget *worksheet){
    ui->tabWidget->insertTab(index, worksheet, title);
}

void Wbook::emitIndexChange(int index){
    emit changedIndex(index);
}

