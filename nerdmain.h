#ifndef NERDMAIN_H
#define NERDMAIN_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <about.h>
#include <currentrecord.h>
#include <qsystemhotkey.h>
#include <parsefile.h>

namespace Ui {
class NerdMain;
}

class NerdMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit NerdMain(QWidget *parent = 0);
    ~NerdMain();

public slots:
    void openFile();

protected:

protected slots:

private slots:
    void openHomepage(void);        // Open CCi homepage.

private:
    Ui::NerdMain *ui;
    QSystemHotkey *hotkey;
    ParseFile *file;
    CurrentRecord *recordTracker;
    About *aboutWin;
};

#endif // NERDMAIN_H
