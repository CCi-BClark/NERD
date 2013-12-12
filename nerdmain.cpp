#include <QDebug>
#include "nerdmain.h"
#include "ui_nerdmain.h"

NerdMain::NerdMain(QWidget *parent): QMainWindow(parent), ui(new Ui::NerdMain){
    ui->setupUi(this);//Set window ui

    // Init pointer values
    hotkey = new QSystemHotkey;
    recordTracker = new CurrentRecord;
    aboutWin = new About;
    file = new ParseFile;

    // UIX open window signal/slots
    connect(ui->menuAbout,SIGNAL(triggered()),aboutWin,SLOT(show()));
    connect(ui->menuHomepage,SIGNAL(triggered()),this,SLOT(openHomepage()));
    connect(ui->btnOpen,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(ui->menuOpen,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->menuExit,SIGNAL(triggered()),this,SLOT(close()));
}

NerdMain::~NerdMain(){

}

void NerdMain::openFile(){
    file->setFile(QFileDialog::getOpenFileName(this,QObject::tr("Open Excel File"), "/home/",QObject::tr("Excel Files (*.xlsx)")));
}

void NerdMain::openHomepage(){
    QDesktopServices::openUrl(QUrl("http://www.cci.edu", QUrl::TolerantMode));
}
