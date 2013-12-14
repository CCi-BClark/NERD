#include "ssheet.h"
#include "ui_ssheet.h"

Ssheet::Ssheet(QWidget *parent) : QWidget(parent), ui(new Ui::Ssheet){
    ui->setupUi(this);
}

Ssheet::~Ssheet(){
    delete ui;
}

void Ssheet::setWidget(ParseSheet data){
    for(int i = 1; i < data.getRowCount(); i++){
        for(int k = 0; k < data.getColumnCount(); k++){
            ui->tableData->setItem(i,k,new QTableWidgetItem(data.getValue(i,k)));
        }
    }
}
