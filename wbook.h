#ifndef WBOOK_H
#define WBOOK_H

#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"
#include <QWidget>

namespace Ui {
class Wbook;
}

class Wbook : public QWidget{
    Q_OBJECT

public:
    explicit Wbook(QWidget *parent = 0);
    ~Wbook();    
    void createTab(int index, QString title, QWidget *worksheet);
signals:
    void changedIndex(int);
public slots:
    void emitIndexChange(int index);

protected:

private:
    Ui::Wbook *ui;
};

#endif // WBOOK_H
