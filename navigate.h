#ifndef NAVIGATE_H
#define NAVIGATE_H

#include <QWidget>
#include <QLayout>
#include <excelmockwidget.h>
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

signals:

public slots:
    void hotkeyPressed(int key);
    void setNextCell(void);
    void setNextRecord(void);
    void setPrevCell(void);
    void setPrevRecord(void);

protected:
    void setSignalSlot(void);

private:
    ExcelMockWidget *excelView;
    NavigateButtons *btnNavigation;
    SystemFocusWidget *btnControlState;
    ParseExcel *parser;
    QHBoxLayout *btnHContainer;
    QVBoxLayout *viewVContainer;

};

#endif // NAVIGATE_H
