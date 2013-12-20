#include "parserecord.h"

ParseRecord::ParseRecord() : ParseSheet(), rowPos(1){
}

ParseRecord::~ParseRecord(){
}

void ParseRecord::setNextRecord(void){
    if (rowPos < getRowCount()-1) {
        rowPos += 1;
    }
}

void ParseRecord::setPrevRecord(void){
    if (rowPos > 1) {
        rowPos -= 1;
    }
}

int ParseRecord::getColumnCount(void){
    return dataStore->currentWorksheet()->dimension().columnCount();
}

int ParseRecord::getCurrentRow(void){
    return rowPos;
}


int ParseRecord::getRowCount(void){
    return dataStore->currentWorksheet()->dimension().rowCount();
}

QStringList ParseRecord::getRecord(int row){
    QStringList record;
    for (int i = 0; i < getColumnCount(); ++i) {
        QString one(dataStore->read(1,i+1).toString());
        QString two(dataStore->read(row+1,i+1).toString());
        QString item = QString("%1 :  %2").arg(one).arg(two);
        record.insert(i,item);
    }
    return record;
}

QStringList ParseRecord::getRow(int index, int row){
    setCurrentWorksheet(index);
    QStringList list;
    for(int i= 1;i <= getColumnCount();i++){
        list << dataStore->read(row,i).toString();
    }
    return list;
}

