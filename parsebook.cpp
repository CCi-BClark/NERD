#include "parsebook.h"

ParseBook::ParseBook(){
    dataStore = new QXlsx::Document;
    range = new QXlsx::CellRange;
}

ParseBook::~ParseBook(){
    delete [] dataStore;
    delete [] range;
}

int ParseBook::getSheetCount(){
    return dataStore->documentPropertyNames().size();
}

void ParseBook::setData(QFileInfo open){
    file = open;
    dataStore = new QXlsx::Document(file.absoluteFilePath());
    range = new QXlsx::CellRange(dataStore->dimension());
    createSheets();
}

QString ParseBook::getFileTitle(){
    return file.fileName();
}

void ParseBook::createSheets(void){
    for(int i = 0; i < getSheetCount(); i++){
        dataStore->setCurrentWorksheet(i);
    }
}
