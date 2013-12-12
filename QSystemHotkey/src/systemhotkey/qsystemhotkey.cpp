#include "qsystemhotkey.h"

QSystemHotkey::QSystemHotkey(){
    running = false;
}

void QSystemHotkey::addKey(int keyID, UINT holdKey, char charKey){
    hotkeys.push_back(keyID);
    RegisterHotKey(NULL,keyID,holdKey | MOD_NOREPEAT,charKey);
}

void QSystemHotkey::removeKey(int keyID){
    for (int i = 0; i < (int)hotkeys.size(); ++i) {
        if(hotkeys.at(i) == keyID){
            UnregisterHotKey(NULL,hotkeys.at(i));
            hotkeys.erase(hotkeys.begin() + i);
        }
    }
}

int QSystemHotkey::getHotkey(int position){
    return hotkeys.at(position);
}

void QSystemHotkey::beginHotkeys(){
    running = true;
    listen();
}

void QSystemHotkey::haltHotkeys(){
    running = false;
}

void QSystemHotkey::listen(){
    while(running){
        GetMessage(&msg,NULL,0,0);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (msg.message == WM_HOTKEY){
            for (int i = 0; i < (int)hotkeys.size(); ++i) {
                if (msg.wParam == (unsigned int)hotkeys.at(i)) run(i);
            }
        }
    }
}

void QSystemHotkey::run(int position){
    emit runHotkey(position);
}
