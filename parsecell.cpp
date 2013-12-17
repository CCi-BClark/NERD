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
    QString val1(dataStore->read(row,column).toString());
    QString val2(dataStore->cellAt(row,column)->value().toString());
    QXlsx::Cell *val3(dataStore->cellAt(row,column));
    QXlsx::Format val4(val3->format());

    return val3->value();
}
