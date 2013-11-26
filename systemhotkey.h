#ifndef SYSTEMHOTKEY_H
#define SYSTEMHOTKEY_H
#define MOD_NOREPEAT    0x4000
#define MOD_CONTROL     0x0002
#define MOD_ALT         0x0001

#include <string>
#include <vector>
#include "stdafx.h"


class SystemHotkey {
public:
    explicit SystemHotkey(void);
    ~SystemHotkey();

    void addKey(int keyID, UINT holdKey, char charKey);
    void connectFunction(int keyID, std::string func);
    void removeKey(int keyID);

    void beginHotkeys(void);
    void haltHotkeys(void);

public:

private:
    typedef std::pair<int, std::string> key;

    void listen(void);
    void run(int wParam);

    bool running;
    MSG msg;
    std::vector<key> hotkeys;
};

#endif // SYSTEMHOTKEY_H
