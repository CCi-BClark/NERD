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
    setMenuKeys();
    setSignalSlot();
}

NerdMain::~NerdMain(){
    delete aboutWin;
    delete data;
    delete open;
    delete mainLayout;
}

void NerdMain::openFile(void){
    QString name(data->getDataFileName());
    if(name != NULL) {
        delete data;
        data = new Navigate;
        open->btnToggle();
        openFile();
    } else {
        data->setDataFile(QFileDialog::getOpenFileName(this,QObject::tr("Open Excel File"), "/home/",QObject::tr("Excel Files (*.xlsx)")));
        name.append(data->getDataFileName());
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
    connect(ui->menuOpen,SIGNAL(triggered()),open,SLOT(btnClicked()));
    connect(ui->menuExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->menuStart,SIGNAL(triggered()),data,SLOT(toggleState()));

    connect(ui->menuNextRecord,SIGNAL(triggered()),data,SLOT(setNextRecord()));
    connect(ui->menuPrevRecord,SIGNAL(triggered()),data,SLOT(setPrevRecord()));
    connect(ui->menuNextCell,SIGNAL(triggered()),data,SLOT(setNextCell()));
    connect(ui->menuPrevCell,SIGNAL(triggered()),data,SLOT(setPrevCell()));
}

void NerdMain::setMenuKeys(){
    ui->menuExit->setShortcut(Qt::CTRL + Qt::Key_Q);
    ui->menuOpen->setShortcut(Qt::CTRL + Qt::Key_O);
    ui->menuStart->setShortcut(Qt::CTRL + Qt::Key_S);
    ui->menuStop->setShortcut(Qt::CTRL + Qt::Key_S);
    ui->menuNextCell->setShortcut(Qt::CTRL + Qt::Key_X);
    ui->menuPrevCell->setShortcut(Qt::CTRL + Qt::Key_A);
    ui->menuNextRecord->setShortcut(Qt::ALT + Qt::Key_X);
    ui->menuPrevRecord->setShortcut(Qt::ALT + Qt::Key_A);
}

void NerdMain::openHomepage(){
    QDesktopServices::openUrl(QUrl("http://www.cci.edu", QUrl::TolerantMode));
}
