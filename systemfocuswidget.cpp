#include "systemfocuswidget.h"
#include "ui_systemfocuswidget.h"

SystemFocusWidget::SystemFocusWidget(QWidget *parent) : QWidget(parent), ui(new Ui::SystemFocusWidget){
    isOn = false;
    recordView = new CurrentRecord;
    hotkeys = new QSystemHotkey;

    ui->setupUi(this);
    hotkeys->addKey(200,MOD_ALT,'X');
    hotkeys->addKey(300,MOD_CONTROL,'X');
    hotkeys->addKey(400,MOD_ALT,'A');
    hotkeys->addKey(500,MOD_CONTROL,'A');

    connect(ui->btn,SIGNAL(clicked()),this,SLOT(clickToggle()));
    connect(hotkeys,SIGNAL(runHotkey(int)),this,SLOT(emitKey(int)));
}

SystemFocusWidget::~SystemFocusWidget(){
    delete ui;
}

void SystemFocusWidget::setRecord(QStringList record){
    recordView->setRecord(record);
}

void SystemFocusWidget::clickToggle(){
    if(isOn){
        isOn = false;
        setTitle("Start");
        recordView->hide();
        QApplication::processEvents();
        hotkeys->haltHotkeys();
    } else {
        isOn = true;
        setTitle("Stop");
        recordView->show();
        QApplication::processEvents();
        hotkeys->beginHotkeys();
    }
}

void SystemFocusWidget::emitKey(int key){
    emit hotkey(key);
}

void SystemFocusWidget::setTitle(QString title){
    ui->btn->setText(title);
}
