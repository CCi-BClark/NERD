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
    // Make listView generic control function.
    QStandardItemModel *headModel = new QStandardItemModel(0);
    for (int i = 0; i < header.size(); ++i) {
        QStandardItem *item;
        item = new QStandardItem(header.at(i));
        headModel->appendRow(item);
    }
    ui->headerView->setModel(headModel);
    ui->listWidget->insertItems(0,record);

    ui->hbox->setAlignment(Qt::AlignLeft);
    ui->vbox->setAlignment(Qt::AlignLeft);
    setWidth(header,record);
    setHeight(header.size(),record.size());
    this->layout()->setAlignment(this,Qt::AlignLeft);
    this->adjustSize();
}

void CurrentRecord::clearList(){
    selectedItem = 0;
    ui->headerView->clearFocus();
    ui->listWidget->clear();
}

void CurrentRecord::setSelection(int column){
    ui->listWidget->itemSelectionChanged();
    ui->listWidget->item(column)->setSelected(true);
    selectedItem = column;
    setClipBoard();
}

void CurrentRecord::setWidth(QStringList header, QStringList record){
    int headerWidth = 0;
    for (int i = 0; i < header.size(); ++i) {
        if (headerWidth < header.at(i).length()) {
            headerWidth = header.at(i).length();
        }
    }
    int recordWidth = 15;
    for (int i = 0; i < record.size(); ++i) {
        if (recordWidth < record.at(i).length()) {
            recordWidth = record.at(i).length();
        }
    }
    ui->headerView->setMaximumWidth((headerWidth*8));
    ui->listWidget->setMaximumWidth((recordWidth*8));
    ui->headerView->setMinimumWidth((headerWidth*8));
    ui->listWidget->setMinimumWidth((recordWidth*8));
}

void CurrentRecord::setHeight(int header, int record){
    ui->headerView->setMinimumHeight(header*3);
    ui->listWidget->setMinimumHeight(record*3);
}

void CurrentRecord::setClipBoard(){
    clipboard = QApplication::clipboard();
    clipboard->setText(ui->listWidget->item(selectedItem)->text());
}
