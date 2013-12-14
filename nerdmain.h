#ifndef NERDMAIN_H
#define NERDMAIN_H

#include <QMainWindow>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QUrl>
#include <about.h>
#include <fileopen.h>
#include <currentrecord.h>
#include <qsystemhotkey.h>
#include <wbook.h>

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
    void openFile(void);
    void toggleLayout(int control);

protected:

protected slots:

private slots:
    void openHomepage(void);        // Open CCi homepage.

private:
    Ui::NerdMain *ui;
    Wbook *file;
    FileOpen *open;
    CurrentRecord *recordTracker;
    About *aboutWin;
    QVBoxLayout *mainLayout;
    QSystemHotkey *hotkey;
};

#endif // NERDMAIN_H
