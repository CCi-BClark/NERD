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
    QXlsx::Cell *val3(dataStore->cellAt(row,column));
    return val3->value();
}

void ParseCell::setNextRecord(){
    columnPos = 0;
    ParseRecord::setNextRecord();
}

void ParseCell::setPrevRecord(){
    columnPos = 0;
    ParseRecord::setPrevRecord();
}
