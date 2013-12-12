#ifndef WBOOK_H
#define WBOOK_H

#include "parsebook.h"
#include "xlsxdocument.h"
#include "xlsxcell.h"
#include "xlsxcellrange.h"
#include "xlsxformat.h"
#include "xlsxdatavalidation.h"
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
    void setData(QFileInfo info);
protected:
    void createTabs(void);
    void createTab(QString title);

private:
    Ui::Wbook *ui;
    ParseBook *file;
};

#endif // WBOOK_H
