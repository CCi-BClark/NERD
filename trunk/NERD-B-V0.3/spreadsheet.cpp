#include "spreadsheet.h"
#include "ui_spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent) :
    QWidget(parent), ui(new Ui::Spreadsheet){
    ui->setupUi(this);
}

Spreadsheet::~Spreadsheet(){
    delete ui;
}

void Spreadsheet::setTable(QXlsx::Document *&file){
    ui->tableData->setColumnCount(range->columnCount());  // must be run first
    ui->tableData->setRowCount(range->rowCount()-1);     // must be run first
    QStringList headerList;
    for(int i= 1;i <= range->columnCount();i++){
        headerList << dataStore->read(1,i).toString();
    }
    ui->tableData->setHorizontalHeaderLabels(headerList);
    ui->tableData->resizeRowsToContents();
    ui->tableData->resizeColumnsToContents();
    ui->tableData->verticalHeader()->setVisible(false);

    ui->tableData->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableData->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableData->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableData->setShowGrid(false);
    for(int i = 1; i <= range->rowCount()-1; i++){
        for(int k = 0; k <= range->columnCount()-1;k++){
            QString val;
            if(dataStore->cellAt(i+1,k+1) == NULL) {val.append("");}
            else {val.append(dataStore->cellAt(i+1,k+1)->value().toString());}
            ui->tableData->setItem(i-1,k,new QTableWidgetItem(val,0));
        }
    }
}

void Spreadsheet::setCurrentRecord(int row){
    ui->tableData->selectRow(row);
    ui->tableData->setCurrentCell(row,1);
    winRecord->setRecordNum(row+1);
    if(0 == row){
        ui->btnPrev->setEnabled(false);
        ui->btnPrevCell->setEnabled(false);
        ui->btnNext->setEnabled(true);
        ui->btnNextCell->setEnabled(true);
    } else if (range->rowCount()-2 == row){
        ui->btnPrev->setEnabled(true);
        ui->btnPrevCell->setEnabled(true);
        ui->btnNext->setEnabled(false);
    }
}

void Spreadsheet::setCurrentCell(int row, int col){
    ui->tableData->setCurrentCell(row,col);
    ui->tableData->selectRow(row);
    if(row+1 != winRecord->getRecordNum()){
        winRecord->setRecordNum(row+1);
    }
    winRecord->setDataItem(col);
}

void Spreadsheet::setNextRecord(){
    int current = winRecord->getRecordNum();
    if(0 < current) {
        setCurrentRecord(current);
    }
    if(!ui->btnPrev->isEnabled()){
        ui->btnPrev->setEnabled(true);
        ui->btnPrevCell->setEnabled(true);
    }
}

void Spreadsheet::setPrevRecord(){
    int current = winRecord->getRecordNum()-1;
    if (current > 0){
        if (current == 1) {
            ui->btnPrev->setEnabled(false);
            ui->btnPrevCell->setEnabled(false);
        }
        setCurrentRecord(current-1);
    }
    if(!ui->btnNext->isEnabled()){
        ui->btnNext->setEnabled(true);
        ui->btnNextCell->setEnabled(true);
    }
}

void Spreadsheet::setNextCell(){
    int currentCol = winRecord->getColumnNum();
    int currentRow = winRecord->getRecordNum()-1;

    if(currentCol < range->columnCount()-1) {
        if (!ui->btnPrevCell->isEnabled()){
            ui->btnPrevCell->setEnabled(true);
        }
        if (!ui->btnNext->isEnabled()){
            ui->btnNextCell->setEnabled(false);
        }
        setCurrentCell(currentRow, currentCol+1);
    } else {
        if(!ui->btnPrev->isEnabled()){
            ui->btnPrev->setEnabled(true);
        }
        if(currentRow < range->rowCount()-2){
            setNextRecord();
        }
    }
}

void Spreadsheet::setPrevCell(){
    int currentCol = winRecord->getColumnNum();
    int currentRow = winRecord->getRecordNum()-1;

    if (currentCol > 0){
        if (!ui->btnNextCell->isEnabled()){
            ui->btnNextCell->setEnabled(true);
        }
        if (!ui->btnPrev->isEnabled()) {
            ui->btnPrevCell->setEnabled(false);
        }
        setCurrentCell(currentRow,currentCol-1);
    } else {
        if(!ui->btnNext->isEnabled()){
            ui->btnNext->setEnabled(true);
        }
        if (currentRow > 0) {
            if(currentRow == 1){
                ui->btnPrev->setEnabled(false);
            }
            setCurrentCell(currentRow-1, range->columnCount()-1);
        } else {
            ui->btnPrevCell->setEnabled(false);
        }
    }
}
