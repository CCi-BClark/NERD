#ifndef NAVIGATE_H
#define NAVIGATE_H

#include <QWidget>
#include <QLayout>
#include <excelview.h>
#include <navigatebuttons.h>
#include <parseexcel.h>
#include <systemfocuswidget.h>

class Navigate : public QWidget
{
    Q_OBJECT
public:
    explicit Navigate(QWidget *parent = 0);
    ~Navigate();
    void setDataFile(QFileInfo file);
    QString getDataFileName(void);

signals:
    void stateChange(void);
    void nextState(bool);
    void prevState(bool);
    void nextCellState(bool);
    void prevCellState(bool);
    void cellLocation(int, int);

public slots:
    void sheetIndexChanged(int index);
    void hotkeyPressed(int key);
    void setNextCell(void);
    void setNextRecord(void);
    void setPrevCell(void);
    void setPrevRecord(void);
    void toggleState(void);

protected:
    void setSignalSlot(void);

protected slots:
    void emitState(void);
    void emitLocation(void);

private:
    void lastRowToggle(void);
    void lastColumnToggle(void);
    void firstColumnToggle(void);
    void firstRowToggle(void);
    void nextCell(void);
    void prevCell(void);

    ExcelView *excelView;
    NavigateButtons *btnNavigation;
    SystemFocusWidget *focusRecord;
    ParseExcel *parser;
    QHBoxLayout *btnHContainer;
    QVBoxLayout *viewVContainer;
    QStringList headerList;

};

#endif // NAVIGATE_H
