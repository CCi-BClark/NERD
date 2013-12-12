#ifndef SSHEET_H
#define SSHEET_H

#include <QWidget>

namespace Ui {
class Ssheet;
}

class Ssheet : public QWidget
{
    Q_OBJECT

public:
    explicit Ssheet(QWidget *parent = 0);
    ~Ssheet();

private:
    Ui::Ssheet *ui;
};

#endif // SSHEET_H
