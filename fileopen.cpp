#include "fileopen.h"
#include "ui_fileopen.h"

FileOpen::FileOpen(QWidget *parent) : QWidget(parent), ui(new Ui::FileOpen), toggle(0){
    ui->setupUi(this);
    connect(ui->btnOpen,SIGNAL(clicked()),this,SLOT(btnClicked()));
}

FileOpen::~FileOpen(){
    delete ui;
}

void FileOpen::btnClicked(){
    btnToggle();
    emit fileOpen();
}

int FileOpen::isOpen(){
    return toggle;
}

void FileOpen::setFileName(QString name){
    ui->labCurrent->setText(name);
}

void FileOpen::btnToggle(){
    if(toggle){
        toggle = 0;
        setFileName("None");
    } else {
        toggle = 1;
    }
}
