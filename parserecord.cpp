#include "parserecord.h"

ParseRecord::ParseRecord() : ParseSheet(){
}

ParseRecord::~ParseRecord(){
}

void ParseRecord::setNextRecord(void){
}

void ParseRecord::setPrevRecord(void){
}

int ParseRecord::getColumnCount(int index){
    setCurrentWorksheet(index);
    return dataStore->currentWorksheet()->dimension().columnCount();
}

int ParseRecord::getRowCount(int index){
    setCurrentWorksheet(index);
    return dataStore->currentWorksheet()->dimension().rowCount();
}

QStringList ParseRecord::getRow(int index, int row){
    setCurrentWorksheet(index);
    QStringList list;
    for(int i= 1;i <= getColumnCount(index);i++){
        list << dataStore->read(row,i).toString();
    }
    return list;
}

