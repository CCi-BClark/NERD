#include "recordwindow.h"
#include "ui_recordwindow.h"
#include <QDebug>

RecordWindow::RecordWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordWindow){
    ui->setupUi(this);
}

RecordWindow::~RecordWindow(){
    delete ui;
}

void RecordWindow::setRecords(QXlsx::Document *&file){
    dataStore = file;
    setRecordTotal();
    setRecordNum(1);
}

void RecordWindow::setRecordNum(int rec){
    currentR = (int)rec;
    QString line,
            tcount;
    tcount.setNum(total);
    line.setNum(currentR).append(" / ").append(tcount);

    ui->labCurrentNum->setText(line);
    setRecordDisplay();
}

void RecordWindow::setRecordTotal(){
    total = (int)dataStore->dimension().rowCount()-1;
}

void RecordWindow::setRecordDisplay(){
    ui->listData->clear();
    for(int i = 1; i < (int)dataStore->dimension().columnCount()+1; i++){
        QString line(dataStore->read(1, i).toString() + " : ");
        line.append(dataStore->read(currentR+1, i).toString());

        ui->listData->insertItem(i-1,line);
    }
    setDataItem(0);
}

void RecordWindow::setDataItem(int item){
    currentC = item;
    ui->listData->itemSelectionChanged();
    ui->listData->item(currentC)->setSelected(true);
    setClipBoard();
}

void RecordWindow::setClipBoard(){
    clipboard = QApplication::clipboard();
    clipboard->setText(dataStore->read(currentR+1, currentC+1).toString());
}

int RecordWindow::getRecordNum(){
    return currentR;
}
