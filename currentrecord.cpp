#include "currentrecord.h"
#include "ui_currentrecord.h"

CurrentRecord::CurrentRecord(QWidget *parent) : QWidget(parent), ui(new Ui::CurrentRecord){
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    this->move(0,0);
}

CurrentRecord::~CurrentRecord(){
    delete ui;
}

void CurrentRecord::setRecord(QStringList record){
    clearList();
    for (int i = 0; i < record.size(); ++i) {
        QString item(record.at(i));
        ui->listWidget->insertItem(i,item);
    }    
    ui->listWidget->itemSelectionChanged();
    ui->listWidget->item(0)->setSelected(true);
}

void CurrentRecord::clearList(){
    ui->listWidget->clear();
}
