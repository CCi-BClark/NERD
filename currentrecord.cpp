#include "currentrecord.h"
#include "ui_currentrecord.h"

CurrentRecord::CurrentRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurrentRecord)
{
    ui->setupUi(this);
}

CurrentRecord::~CurrentRecord()
{
    delete ui;
}
