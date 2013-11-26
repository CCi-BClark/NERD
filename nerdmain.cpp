#define MOD_NOREPEAT    0x4000
#define MOD_ALT         0x0001
#include "stdafx.h"
#include <QDebug>
#include "nerdmain.h"
#include "ui_nerdmain.h"
#include <windows.h>
#include <QSizePolicy>


NerdMain::NerdMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NerdMain){
    ui->setupUi(this);
    winRecord = new RecordWindow;
    hotkey = new SystemHotkey;
    toggleDataElem(false);

    // UIX windows
    connect(ui->menuAbout,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->menuHomepage,SIGNAL(triggered()),this,SLOT(openHomepage()));
    connect(ui->btnOpen,SIGNAL(clicked()),this,SLOT(open()));
    connect(ui->menuOpen,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->menuExit,SIGNAL(triggered()),this,SLOT(close()));

    // Record setup
    connect(ui->btnStart,SIGNAL(clicked()),this,SLOT(startStop()));
    connect(winRecord,SIGNAL(finished(int)),this,SLOT(startStop()));
    connect(winRecord,SIGNAL(finished(int)),hotkey,SLOT(haltHotkeys()));
    connect(ui->tableData, SIGNAL(cellEntered(int,int)),this,SLOT(setCurrentRecord(int)));
    connect(ui->tableData, SIGNAL(cellDoubleClicked(int,int)),this,SLOT(setCurrentCell(int,int)));

    // Record Navigation
    connect(ui->btnNext,SIGNAL(clicked()),this,SLOT(setNextRecord()));
    connect(ui->btnPrev,SIGNAL(clicked()),this,SLOT(setPrevRecord()));
    connect(ui->btnNextCell,SIGNAL(clicked()),this,SLOT(setNextCell()));
    connect(ui->btnPrevCell,SIGNAL(clicked()),this,SLOT(setPrevCell()));
    connect(ui->menuNextRecord,SIGNAL(triggered()),this,SLOT(setNextRecord()));
    connect(ui->menuPrevRecord,SIGNAL(triggered()),this,SLOT(setPrevRecord()));
    connect(ui->menuNextCell,SIGNAL(triggered()),this,SLOT(setNextCell()));
    connect(ui->menuPrevCell,SIGNAL(triggered()),this,SLOT(setPrevCell()));
    connect(hotkey, SIGNAL(runHotkey(int)),this,SLOT(hotkeyPressed(int)));

    // Create application window hotkeys
    ui->menuExit->setShortcut(Qt::CTRL + Qt::Key_Q);
    ui->menuOpen->setShortcut(Qt::CTRL + Qt::Key_O);
    ui->menuStart->setShortcut(Qt::CTRL + Qt::Key_S);
    ui->menuStop->setShortcut(Qt::CTRL + Qt::Key_S);
    ui->menuNextCell->setShortcut(Qt::CTRL + Qt::Key_X);
    ui->menuPrevCell->setShortcut(Qt::CTRL + Qt::Key_A);
    ui->menuNextRecord->setShortcut(Qt::ALT + Qt::Key_X);
    ui->menuPrevRecord->setShortcut(Qt::ALT + Qt::Key_A);
}

// (Start) Help Menu functions
void NerdMain::about(){
    AboutWindow *winAbout;
    winAbout = new AboutWindow;
    winAbout->show();
}

void NerdMain::openHomepage(){
    QDesktopServices::openUrl(QUrl("http://www.cci.edu", QUrl::TolerantMode));
}
// (Stop)

NerdMain::~NerdMain(){
    delete ui;
}

// (Start) Init data and elements.
void NerdMain::setFileLabel(QString label){
    ui->labCurrent->setText(label);
}

void NerdMain::setFile(){
    fileInfo = QFileDialog::getOpenFileName(this,tr("Open Excel File"), "/home/", tr("Excel Files (*.xlsx)"));
    if(fileInfo.fileName() != NULL) {
        toggleDataElem(true);
        dataStore = new QXlsx::Document(fileInfo.absoluteFilePath());
        range = new QXlsx::CellRange(dataStore->dimension());
        setFileLabel(fileInfo.fileName());
        setTable();
        winRecord->setRecords(dataStore);
    }
}

void NerdMain::setTable(){
    ui->tableData->setColumnCount(range->columnCount());  // must be run first
    ui->tableData->setRowCount(range->rowCount()-1);     // must be run first
    QStringList headerList;
    for(int i= 1;i <= range->columnCount();i++){
        headerList << dataStore->read(1,i).toString();
    }
    ui->tableData->setHorizontalHeaderLabels(headerList);
    ui->tableData->resizeRowsToContents();
    ui->tableData->resizeColumnsToContents();
    ui->tableData->verticalHeader()->setVisible(false);

    ui->tableData->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableData->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableData->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableData->setShowGrid(false);
    for(int i = 1; i <= range->rowCount()-1; i++){
        for(int k = 1; k <= range->columnCount();k++){
            ui->tableData->setItem(i-1,k-1,new QTableWidgetItem(dataStore->read(i+1,k).toString()));
        }
    }
}

void NerdMain::open(){
    if(fileInfo.fileName() != NULL){
        setFileLabel("None");
        toggleDataElem(false);
        setFile();
    } else {
        setFile();
    }
}
void NerdMain::toggleDataElem(bool isData){
    if(isData){
        ui->btnPrev->setEnabled(false);
        ui->btnPrev->setHidden(false);
        ui->btnNext->setHidden(false);
        ui->btnPrevCell->setHidden(false);
        ui->btnNextCell->setHidden(false);
        ui->tableData->setHidden(false);
        ui->btnOpen->setText("Change File");
        ui->btnStart->setHidden(false);
        this->resize(400,400);
        ui->menuRun->setEnabled(true);
        //this->setSizePolicy(QSizePolicy::verticalPolicy());
    } else {
        ui->btnPrev->setEnabled(false);
        ui->btnPrev->setHidden(true);
        ui->btnNext->setHidden(true);
        ui->btnPrevCell->setHidden(true);
        ui->btnNextCell->setHidden(true);
        ui->tableData->setHidden(true);
        ui->btnOpen->setText("Open File");
        ui->btnStart->setHidden(true);
        this->resize(400, 60);
        ui->menuRun->setEnabled(false);
        this->sizePolicy().setHorizontalPolicy(QSizePolicy::Minimum);
    }
}
// (Stop)

// (Start) Navigate cell content functions.
void NerdMain::setCurrentRecord(int row){
    ui->tableData->selectRow(row);
    ui->tableData->setCurrentCell(row,1);
    winRecord->setRecordNum(row+1);
    if(0 == row){
        ui->btnPrev->setEnabled(false);
        ui->btnNext->setEnabled(true);
    } else if (range->rowCount()-2 == row){
        ui->btnPrev->setEnabled(true);
        ui->btnNext->setEnabled(false);
    }
}

void NerdMain::setCurrentCell(int row, int col){
    ui->tableData->setCurrentCell(row,col);
    ui->tableData->selectRow(row);
    if(row+1 != winRecord->getRecordNum()){
        winRecord->setRecordNum(row+1);
    }
    winRecord->setDataItem(col);
}

void NerdMain::setNextRecord(){
    int current = winRecord->getRecordNum();
    if(0 < current) {
        setCurrentRecord(current);
    }
    if(!ui->btnPrev->isEnabled()){
        ui->btnPrev->setEnabled(true);
    }
}

void NerdMain::setPrevRecord(){
    int current = winRecord->getRecordNum()-1;
    if (current >= 0){
        if (current == 1) {
            ui->btnPrev->setEnabled(false);
        }
        setCurrentRecord(current-1);
    }
    if(!ui->btnNext->isEnabled()){
        ui->btnNext->setEnabled(true);
    }
}

void NerdMain::setNextCell(){
    int currentCol = winRecord->getColumnNum();
    int currentRow = winRecord->getRecordNum()-1;

    if(currentCol < range->columnCount()-1) {
        setCurrentCell(currentRow, currentCol+1);
    } else {
        if(!ui->btnPrev->isEnabled()){
            ui->btnPrev->setEnabled(true);
        }
        if(currentRow < range->rowCount()-2){
            setNextRecord();
        }
    }
}

void NerdMain::setPrevCell(){
    int currentCol = winRecord->getColumnNum();
    int currentRow = winRecord->getRecordNum()-1;

    if (currentCol > 0){
        setCurrentCell(currentRow,currentCol-1);
    } else {
        if(!ui->btnNext->isEnabled()){
            ui->btnNext->setEnabled(true);
        }
        if (currentRow > 0) {
            setCurrentCell(currentRow-1, range->columnCount()-1);
        }
    }
}

void NerdMain::hotkeyPressed(int position){
    int val = hotkey->getHotkey(position);
    switch (val) {
    case 1:
        setPrevCell();
        break;
    case 2:
        setNextCell();
        break;
    case 3:
        setPrevRecord();
        break;
    case 4:
        setNextRecord();
        break;
    default:
        break;
    }
}
// (Stop)

// (Start) Start/stop sequence functions.
void NerdMain::startStop(){
    bool menu = ui->menuStart->isEnabled();
    if(!menu){
        stop();
    } else {
        start();
    }
}

void NerdMain::start(){
    toggleMenu(true);
    hotkey->addKey(1, MOD_CONTROL, 'A');
    hotkey->addKey(2, MOD_CONTROL, 'X');
    hotkey->addKey(3, MOD_ALT, 'A');
    hotkey->addKey(4, MOD_ALT, 'X');
    hotkey->connectFunction(1,"setPrevCell()");
    hotkey->connectFunction(2,"setNextCell()");
    hotkey->connectFunction(3,"setPrevRecord()");
    hotkey->connectFunction(4,"setNextRecord()");
    winRecord->show();
    QApplication::processEvents();
    hotkey->beginHotkeys();
}

void NerdMain::stop(){
    toggleMenu(false);
    hotkey->removeKey(3);
    hotkey->removeKey(4);
    winRecord->hide();
    hotkey->haltHotkeys();
}

void NerdMain::toggleMenu(bool tf){
    if(tf){
       ui->menuStop->setEnabled(true);
       ui->menuStart->setEnabled(false);
       ui->btnStart->setText("Stop");
    } else {
        ui->menuStop->setEnabled(false);
        ui->menuStart->setEnabled(true);
        ui->btnStart->setText("Start");
    }
}
// (Stop)
