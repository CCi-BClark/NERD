#include "parsecell.h"

ParseCell::ParseCell(){
}

ParseCell::~ParseCell(){
}

void ParseCell::setNextCell(void){
}

void ParseCell::setPrevCell(void){
}

int ParseCell::getCurrentRow(void){
    return rowPos;
}

int ParseCell::getCurrentColumn(void){
    return columnPos;
}

QVariant ParseCell::getCell(int row, int column){
    return dataStore->read(row+1,column+1);
}
