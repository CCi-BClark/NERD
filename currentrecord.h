#ifndef CURRENTRECORD_H
#define CURRENTRECORD_H

#include <QWidget>
#include "windows.h"
#include <QVector>

namespace Ui {
class CurrentRecord;
}

class CurrentRecord : public QWidget
{
    Q_OBJECT

public:
    explicit CurrentRecord(QWidget *parent = 0);
    ~CurrentRecord();
    void setRecord(QStringList record);
    void clearList(void);

private:
    Ui::CurrentRecord *ui;
};

#endif // CURRENTRECORD_H
