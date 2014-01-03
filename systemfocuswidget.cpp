#include "systemfocuswidget.h"
#include "ui_systemfocuswidget.h"

SystemFocusWidget::SystemFocusWidget(QWidget *parent) : QWidget(parent), ui(new Ui::SystemFocusWidget){
    isOn = false;
    recordView = new CurrentRecord;
    hotkeys = new QSystemHotkey;

    ui->setupUi(this);
    hotkeys->addKey(300,MOD_ALT,'X');
    hotkeys->addKey(200,MOD_CONTROL,'X');
    hotkeys->addKey(500,MOD_ALT,'A');
    hotkeys->addKey(400,MOD_CONTROL,'A');

    connect(ui->btn,SIGNAL(clicked()),this,SLOT(clickToggle()));
    connect(hotkeys,SIGNAL(runHotkey(int)),this,SLOT(emitKey(int)));
}

SystemFocusWidget::~SystemFocusWidget(){
    delete ui;
}

void SystemFocusWidget::setRecord(QStringList header, QStringList record){
    recordView->setRecord(header, record);
}

void SystemFocusWidget::setSelection(int column){
    recordView->setSelection(column);
}

void SystemFocusWidget::clickToggle(){
    if(isOn){
        emit changeSystemFocus();
        isOn = false;
        setTitle("Start");
        recordView->hide();
        QApplication::processEvents();
        hotkeys->haltHotkeys();
    } else {
        emit changeSystemFocus();
        isOn = true;
        setTitle("Stop");
        recordView->show();
        recordView->setSelection(0);
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
