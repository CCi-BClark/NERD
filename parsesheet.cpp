#include "parsesheet.h"

ParseSheet::ParseSheet() : sheetPos(0){
}

ParseSheet::~ParseSheet(){
}

void ParseSheet::setNextSheet(){
}

void ParseSheet::setPrevSheet(){
}

int ParseSheet::sheetIndex(){
    return sheetPos;
}

void ParseSheet::setCurrentWorksheet(int index){
    dataStore->setCurrentWorksheet(index);
    sheetPos = index;
}
