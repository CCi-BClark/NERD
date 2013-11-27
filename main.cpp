#include "nerdmain.h"
#include <QApplication>
#include <QtCore/QtGlobal>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NerdMain w;
    w.show();
    return a.exec();
}
