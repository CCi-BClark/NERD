#include "systemhotkey.h"
#include <QDebug>

SystemHotkey::SystemHotkey(QObject *parent) :
    QObject(parent) {
    running = false;
}

SystemHotkey::~SystemHotkey(){

}

void SystemHotkey::removeKey(int keyID){
    for (int i = 0; i < (int)hotkeys.size(); ++i) {
        std::pair<int, std::string> val = hotkeys.at(i);
        if(val.first == keyID){
            UnregisterHotKey(NULL,val.first);
            hotkeys.erase(hotkeys.begin() + i);
        }
    }
}

int SystemHotkey::getHotkey(int position){
    std::pair<int, std::string> val = hotkeys.at(position);
    return val.first;
}

void SystemHotkey::addKey(int keyID, UINT holdKey, char charKey){
    RegisterHotKey(NULL,keyID,holdKey | MOD_NOREPEAT,charKey);
}

void SystemHotkey::connectFunction(int keyID, std::string func){
    hotkeys.push_back(key(keyID,func));
}

void SystemHotkey::beginHotkeys(){
    running = true;
    listen();
}

void SystemHotkey::haltHotkeys(){
    running = false;
}

void SystemHotkey::listen(){
    while(running){
        GetMessage(&msg,NULL,0,0);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (msg.message == WM_HOTKEY){
            for (int i = 0; i < (int)hotkeys.size(); ++i) {
                std::pair<int, std::string> val = hotkeys.at(i);
                if (msg.wParam == (unsigned int)val.first) run(i);
            }
        }
    }
}

void SystemHotkey::run(int pos){
    emit runHotkey(pos);
}
