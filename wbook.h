#ifndef WBOOK_H
#define WBOOK_H

#include <QWidget>

namespace Ui {
class Wbook;
}

class Wbook : public QWidget
{
    Q_OBJECT

public:
    explicit Wbook(QWidget *parent = 0);
    ~Wbook();

private:
    Ui::Wbook *ui;
};

#endif // WBOOK_H
