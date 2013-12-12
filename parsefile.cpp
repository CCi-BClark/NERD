#include "parsefile.h"

ParseFile::ParseFile(): file(NULL){    
    dataStore = new QXlsx::Document;
    clipboard = QApplication::clipboard();
    range = new QXlsx::CellRange;
}

ParseFile::~ParseFile(){
    delete [] dataStore;
    delete [] range;
}

void ParseFile::setFile(QFileInfo open){
    file = open;
    if(file.fileName() != NULL) {
        dataStore = new QXlsx::Document(file.absoluteFilePath());
        range = new QXlsx::CellRange(dataStore->dimension());
    }
}

void ParseFile::getRecordCount(){
}
