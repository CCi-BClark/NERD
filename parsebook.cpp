#include "parsebook.h"

ParseBook::ParseBook(){
    dataStore = new QXlsx::Document;
    range = new QXlsx::CellRange;
    //file = NULL;
}

ParseBook::~ParseBook(){
    delete [] dataStore;
    delete [] range;
}

int ParseBook::getSheetCount(){
    return dataStore->workbook()->worksheets().count();
}

void ParseBook::setData(QFileInfo open){
    file = open;
    dataStore = new QXlsx::Document(file.absoluteFilePath());
    range = new QXlsx::CellRange(dataStore->dimension());
}

void ParseBook::setCurrentWorksheet(int index){
    dataStore->setCurrentWorksheet(index);
}

QString ParseBook::getFileTitle(){
    return file.fileName();
}

QString ParseBook::getSheetTitle(int index){
    setCurrentWorksheet(index);
    return dataStore->currentWorksheet()->sheetName();
}
