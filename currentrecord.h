#ifndef CURRENTRECORD_H
#define CURRENTRECORD_H

#include <QWidget>

namespace Ui {
class CurrentRecord;
}

class CurrentRecord : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentRecord(QWidget *parent = 0);
    ~CurrentRecord();

private:
    Ui::CurrentRecord *ui;
};

#endif // CURRENTRECORD_H
