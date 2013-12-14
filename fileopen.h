#ifndef FILEOPEN_H
#define FILEOPEN_H

#include <QWidget>

namespace Ui {
class FileOpen;
}

class FileOpen : public QWidget
{
    Q_OBJECT

public:
    explicit FileOpen(QWidget *parent = 0);
    ~FileOpen();
    void setFileName(QString name);
public slots:
    void btnClicked(void);
    int isOpen(void);
    void btnToggle(void);
signals:
    void fileOpen(void);
private:
    Ui::FileOpen *ui;
    int toggle;
};

#endif // FILEOPEN_H
