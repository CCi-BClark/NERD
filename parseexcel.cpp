#include "parseexcel.h"

ParseExcel::ParseExcel(QObject *parent) : QObject(parent){
}

ParseExcel::~ParseExcel(){
}

bool ParseExcel::isLastRow(){
    bool tf;
    tf = (getCurrentRow() == (getRowCount()-1));
    return tf;
}

bool ParseExcel::isLastColumn(){
    bool tf;
    tf = (getCurrentColumn() == (getColumnCount()-1));
    return tf;
}

bool ParseExcel::isFirstRow(){
    bool tf;
    tf = (getCurrentRow() == 1);
    return tf;
}

bool ParseExcel::isFirstColumn(){
    bool tf;
    tf = (getCurrentColumn() == 0);
    return tf;
}
