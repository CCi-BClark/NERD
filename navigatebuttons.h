#ifndef NAVIGATEBUTTONS_H
#define NAVIGATEBUTTONS_H

#include <QWidget>

namespace Ui {
class NavigateButtons;
}

class NavigateButtons : public QWidget
{
    Q_OBJECT

public:
    explicit NavigateButtons(QWidget *parent = 0);
    ~NavigateButtons();
    void setNextToggle(int toggle);
    void setPrevToggle(int toggle);

protected:
    void setNextEnabled(bool tf);
    void setNextCellEnabled(bool tf);
    void setPrevEnabled(bool tf);
    void setPrevCellEnabled(bool tf);

signals:
    void clickedNextRecord(void);
    void clickedNextCell(void);
    void clickedPrevRecord(void);
    void clickedPrevCell(void);

public slots:
    void clickNextRecord(void);
    void clickNextCell(void);
    void clickPrevRecord(void);
    void clickPrevCell(void);

private:
    Ui::NavigateButtons *ui;
};

#endif // NAVIGATEBUTTONS_H
