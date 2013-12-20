#include "parsecell.h"

ParseCell::ParseCell() : columnPos(0){
}

ParseCell::~ParseCell(){
}

void ParseCell::setNextCell(void){
    if (columnPos < getColumnCount()) {
        columnPos += 1;
    } else {
        setNextRecord();
    }
}

void ParseCell::setPrevCell(void){
    if (columnPos > 0) {
        columnPos -= 1;
    } else {
        setPrevRecord();
    }
}

int ParseCell::getCurrentColumn(void){
    return columnPos;
}

QVariant ParseCell::getCell(int row, int column){
    QXlsx::Cell *val3(dataStore->cellAt(row,column));
    return val3->value();
}
