#ifndef SYSTEMFOCUSWIDGET_H
#define SYSTEMFOCUSWIDGET_H

#include <QWidget>
#include <currentrecord.h>
#include <qsystemhotkey.h>

namespace Ui {
class SystemFocusWidget;
}

class SystemFocusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemFocusWidget(QWidget *parent = 0);
    ~SystemFocusWidget();

signals:
    void startSystemFocus(void);
    void stopSystemFocus(void);
    void hotkey(int);

public slots:
    void clickToggle(void);
    void emitKey(int key);

protected:
    void setTitle(QString title);

private:
    Ui::SystemFocusWidget *ui;
    BOOL isOn;
    CurrentRecord *recordView;
    QSystemHotkey *hotkeys;
};

#endif // SYSTEMFOCUSWIDGET_H
