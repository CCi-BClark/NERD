#include "ssheet.h"
#include "ui_ssheet.h"

Ssheet::Ssheet(QWidget *parent) : QWidget(parent), ui(new Ui::Ssheet){
    ui->setupUi(this);
}

Ssheet::~Ssheet(){
    delete ui;
}
