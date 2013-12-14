#include <QDebug>
#include "nerdmain.h"
#include "ui_nerdmain.h"

NerdMain::NerdMain(QWidget *parent): QMainWindow(parent), ui(new Ui::NerdMain){
    ui->setupUi(this);//Set window ui
    hotkey = new QSystemHotkey;
    mainLayout = new QVBoxLayout;

    // Init window widgets
    aboutWin = new About;
    file = new Wbook;
    open = new FileOpen;
    recordTracker = new CurrentRecord;

    mainLayout->addWidget(open);
    ui->layout->addLayout(mainLayout);

    // UIX open window signal/slots
    connect(ui->menuAbout,SIGNAL(triggered()),aboutWin,SLOT(show()));
    connect(ui->menuHomepage,SIGNAL(triggered()),this,SLOT(openHomepage()));
    connect(open,SIGNAL(fileOpen()),this,SLOT(openFile()));
    connect(ui->menuOpen,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->menuExit,SIGNAL(triggered()),this,SLOT(close()));
}

NerdMain::~NerdMain(){
    delete hotkey;
    delete recordTracker;
    delete aboutWin;
    delete file;
    delete open;
    delete mainLayout;
}

void NerdMain::openFile(void){
    QString name(file->getFileName());
    if(name != "") {
        delete file;
        file = new Wbook;
        open->btnToggle();
        openFile();
    } else {
        file->setData(QFileDialog::getOpenFileName(this,QObject::tr("Open Excel File"), "/home/",QObject::tr("Excel Files (*.xlsx)")));
        name.append(file->getFileName());
        if(name != NULL) {
            open->setFileName(name);
        } else {
            open->btnToggle();
            if(!file->isHidden()){
                file->hide();
            }
        }
        toggleLayout(open->isOpen());
    }
}

void NerdMain::toggleLayout(int control){
    setMinimumSize(0,0);
    if (control){
        ui->menuRun->setEnabled(true);
        mainLayout->addWidget(file);
        file->show();
    } else {
        ui->menuRun->setEnabled(false);
        mainLayout->removeWidget(file);
        file->hide();
        resize(0, 0);
    }
    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
}

void NerdMain::openHomepage(){
    QDesktopServices::openUrl(QUrl("http://www.cci.edu", QUrl::TolerantMode));
}
