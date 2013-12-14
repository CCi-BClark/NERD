#ifndef SSHEET_H
#define SSHEET_H

#include <QWidget>
#include <QTableWidget>
#include <vector>
#include "parsesheet.h"

namespace Ui {
class Ssheet;
}

class Ssheet : public QWidget
{
    Q_OBJECT
public:
    explicit Ssheet(QWidget *parent = 0);
    ~Ssheet();
    void setWidget(ParseSheet data);
private:
    Ui::Ssheet *ui;
};

#endif // SSHEET_H
