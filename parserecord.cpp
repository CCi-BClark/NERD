#include "parserecord.h"
#include <QDebug>

ParseRecord::ParseRecord() : rowPos(1){
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

QStringList ParseRecord::getRow(int row){
    QStringList list;
    for(int i= 1;i <= getColumnCount();i++){
        if (dataStore->cellAt(row,i) != NULL){
            if (dataStore->cellAt(row,i)->isDateTime()) {
                QString format("MM/dd/yyyy");
                list << dataStore->cellAt(row,i)->dateTime().toString(format);
            } else {
                list << dataStore->cellAt(row,i)->value().toString();
            }
        }
    }
    return list;
}

