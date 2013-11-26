#define MOD_NOREPEAT    0x4000
#define MOD_CONTROL     0x0002
#define MOD_ALT         0x0001

#include "stdafx.h"
#include <QDebug>
#include "nerdmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //RegisterHotKey(NULL,1,MOD_CONTROL | MOD_NOREPEAT,'X');
    //RegisterHotKey(NULL,2,MOD_ALT | MOD_NOREPEAT,'B');

    QApplication a(argc, argv);
    NerdMain w;
    w.show();
    return a.exec();
}
