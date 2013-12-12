#ifndef QSYSTEMHOTKEY_H
#define QSYSTEMHOTKEY_H
#define MOD_NOREPEAT    0x4000
#define MOD_CONTROL     0x0002
#define MOD_ALT         0x0001

#include <vector>
#include <QObject>
#include "windows/stdafx.h"

class QSystemHotkey : public QObject {
    Q_OBJECT

public:
    QSystemHotkey();

    void addKey(int keyID, UINT holdKey, char charKey);
    void removeKey(int keyID);
    int getHotkey(int position);

public slots:
    void beginHotkeys(void);
    void haltHotkeys(void);

signals:
    void runHotkey(int position);

private:
    void listen(void);
    void run(int position);

    bool running;
    MSG msg;
    std::vector<int> hotkeys;
};

#endif // QSYSTEMHOTKEY_H
