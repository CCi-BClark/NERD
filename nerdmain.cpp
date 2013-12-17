#include "nerdmain.h"
#include "ui_nerdmain.h"

NerdMain::NerdMain(QWidget *parent): QMainWindow(parent), ui(new Ui::NerdMain){
    ui->setupUi(this);//Set window ui
    mainLayout = new QVBoxLayout;

    // Init window widgets
    aboutWin = new About;
    data = new Navigate;
    open = new FileOpen;

    mainLayout->addWidget(open);
    ui->layout->addLayout(mainLayout);

    setSignalSlot();
}

NerdMain::~NerdMain(){
    delete aboutWin;
    delete data;
    delete open;
    delete mainLayout;
}

void NerdMain::openFile(void){
    data->setDataFile(QFileDialog::getOpenFileName(this,QObject::tr("Open Excel File"), "/home/",QObject::tr("Excel Files (*.xlsx)")));
    toggleLayout(open->isOpen());
    //COMEBACK AND REDOO LOAD FILE LOGIC DUE TO CHANGES IN OBJECT STRUCTURE!!!
    /*
    QString name("");
    if(name != "") {
        delete data;
        data = new Navigate;
        open->btnToggle();
        openFile();
    } else {
        data->setDataFile(QFileDialog::getOpenFileName(this,QObject::tr("Open Excel File"), "/home/",QObject::tr("Excel Files (*.xlsx)")));
        name.append("");
        if(name != NULL) {
            open->setFileName(name);
        } else {
            open->btnToggle();
            if(!data->isHidden()){
                data->hide();
            }
        }
        toggleLayout(open->isOpen());
    }
    */
}

void NerdMain::toggleLayout(int control){
    setMinimumSize(0,0);
    if (control){
        ui->menuRun->setEnabled(true);
        mainLayout->addWidget(data);
        data->show();
    } else {
        ui->menuRun->setEnabled(false);
        mainLayout->removeWidget(data);
        data->hide();
        resize(0, 0);
    }
    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
}

void NerdMain::setSignalSlot(){
    connect(ui->menuAbout,SIGNAL(triggered()),aboutWin,SLOT(show()));
    connect(ui->menuHomepage,SIGNAL(triggered()),this,SLOT(openHomepage()));
    connect(open,SIGNAL(fileOpen()),this,SLOT(openFile()));
    connect(ui->menuOpen,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->menuExit,SIGNAL(triggered()),this,SLOT(close()));
}

void NerdMain::openHomepage(){
    QDesktopServices::openUrl(QUrl("http://www.cci.edu", QUrl::TolerantMode));
}
