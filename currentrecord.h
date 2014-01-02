#ifndef CURRENTRECORD_H
#define CURRENTRECORD_H

#include <QWidget>
#include <QClipboard>
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
    void setRecord(QStringList header, QStringList record);
    void clearList(void);
    void setSelection(int column);

private:
    void setClipBoard(void);

    Ui::CurrentRecord *ui;
    QClipboard *clipboard;
    int selectedItem;
};

#endif // CURRENTRECORD_H
