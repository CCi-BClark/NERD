#include "currentrecord.h"
#include "ui_currentrecord.h"

CurrentRecord::CurrentRecord(QWidget *parent) : QWidget(parent), ui(new Ui::CurrentRecord), selectedItem(0){
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    this->move(0,0);
}

CurrentRecord::~CurrentRecord(){
    delete ui;
}

void CurrentRecord::setRecord(QStringList header, QStringList record){
    clearList();
    ui->headerWidget->insertItems(0,header);
    ui->listWidget->insertItems(0,record);
    int headerWidth = 0;
    for (int i = 0; i < header.size(); ++i) {
        if (headerWidth < header.at(i).length()) {
            headerWidth = header.at(i).length();
        }
    }
    int recordWidth = 0;
    for (int i = 0; i < record.size(); ++i) {
        if (recordWidth < record.at(i).length()) {
            recordWidth = record.at(i).length();
        }
    }
    ui->hbox->setAlignment(Qt::AlignLeft);
    ui->vbox->setAlignment(Qt::AlignLeft);
    ui->headerWidget->setMaximumWidth((headerWidth*9)+10);
    ui->headerWidget->setMinimumHeight(header.size()*5);
    ui->listWidget->setMaximumWidth((recordWidth*9)+10);
    ui->listWidget->setMinimumHeight(record.size()*5);
    this->adjustSize();
    this->layout()->setAlignment(this,Qt::AlignLeft);
}

void CurrentRecord::clearList(){
    selectedItem = 0;
    ui->headerWidget->clear();
    ui->listWidget->clear();
}

void CurrentRecord::setSelection(int column){
    ui->headerWidget->itemSelectionChanged();
    ui->headerWidget->item(column)->setSelected(true);
    ui->listWidget->itemSelectionChanged();
    ui->listWidget->item(column)->setSelected(true);
    selectedItem = column;
    setClipBoard();
}

void CurrentRecord::setClipBoard(){
    clipboard = QApplication::clipboard();
    clipboard->setText(ui->listWidget->item(selectedItem)->text());
}
