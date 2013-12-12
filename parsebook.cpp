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
    if(file.fileName() != NULL) {
        dataStore = new QXlsx::Document(file.absoluteFilePath());
        range = new QXlsx::CellRange(dataStore->dimension());
    }
}

ParseSheet ParseBook::getSheet(int i){
    return sheets.at(i);
}

void ParseBook::createSheets(void){
    for(int i = 0; i < getSheetCount(); i++){
        dataStore->setCurrentWorksheet(i);
        ParseSheet *sheet;
        sheet = new ParseSheet;
        sheet->setData(*dataStore->currentWorksheet());
        sheets.push_back(*sheet);
    }
}
