#ifndef EXCELMOCKWIDGET_H
#define EXCELMOCKWIDGET_H

#include <QWidget>
#include <wbook.h>

class ExcelMockWidget : public Wbook{
    Q_OBJECT
public:
    explicit ExcelMockWidget(Wbook *parent = 0);
    ~ExcelMockWidget();
signals:

public slots:

private:
};

#endif // EXCELMOCKWIDGET_H
