#include "parsesheet.h"

ParseSheet::ParseSheet(){
}

ParseSheet::~ParseSheet(){
}

void ParseSheet::getCurrentRow(){
}

void ParseSheet::getCurrentColumn(){
}

int ParseSheet::getColumnCount(){
    return sheet->dimension().columnCount();
}

int ParseSheet::getRowCount(){
    return sheet->dimension().rowCount();
}

QString ParseSheet::getTitle(){
    return sheet->sheetName();
}

QString ParseSheet::getValue(int row, int col){
    return sheet->cellAt(row,col)->value().toString();
}

void ParseSheet::setData(QXlsx::Worksheet page){
    sheet = new QXlsx::Worksheet(page);
}

void ParseSheet::setCurrentSheet(int row){
}
