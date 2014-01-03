#ifndef NERDMAIN_H
#define NERDMAIN_H

#include <QMainWindow>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QShortcut>
#include <QShortcut>
#include <about.h>
#include <fileopen.h>
#include <navigate.h>

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
    void setSignalSlot(void);
    void setMenuKeys(void);

protected slots:
    void toggleState(void);
    void toggleNext(bool tf);
    void toggleNextCell(bool tf);
    void togglePrev(bool tf);
    void togglePrevCell(bool tf);

private slots:
    void openHomepage(void);        // Open CCi homepage.

private:
    Ui::NerdMain *ui;
    Navigate *data;
    FileOpen *open;
    About *aboutWin;
    QVBoxLayout *mainLayout;
};

#endif // NERDMAIN_H
