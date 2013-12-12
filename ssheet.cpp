#include "ssheet.h"
#include "ui_ssheet.h"

Ssheet::Ssheet(QWidget *parent) : QWidget(parent), ui(new Ui::Ssheet){
    ui->setupUi(this);
}

Ssheet::~Ssheet(){
    delete ui;
}

void Ssheet::setData(ParseSheet sheet){
    for(int i = 0; i < sheet.getRowCount(); i++){
        for(int k = 0; k < sheet.getColumnCount(); k++){
            ui->tableData->setItem(i,k,new QTableWidgetItem(sheet.getValue(i,k)));
        }
    }
}
