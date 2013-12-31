#include "parsecell.h"

ParseCell::ParseCell() : columnPos(0){

}

ParseCell::~ParseCell(){
}

void ParseCell::setNextCell(void){
    if (columnPos < getColumnCount()-1) {
        columnPos += 1;
    } else {
        setNextRecord();
    }
}

void ParseCell::setPrevCell(void){
    if (columnPos > 0) {
        columnPos -= 1;
    } else {
        columnPos = getColumnCount()-1;
        ParseRecord::setPrevRecord();
    }
}

int ParseCell::getCurrentColumn(void){
    return columnPos;
}

QVariant ParseCell::getCell(int row, int column){
    QVariant val1;
    QXlsx::Cell *val3(dataStore->cellAt(row,column));
    if (val3->isDateTime()) {
        val1 = QVariant(val3->dateTime().date());
    } else {
        val1 = QVariant(val3->value());
    }
    return val1;
}

void ParseCell::setNextRecord(){
    columnPos = 0;
    ParseRecord::setNextRecord();
}

void ParseCell::setPrevRecord(){
    columnPos = 0;
    ParseRecord::setPrevRecord();
}
