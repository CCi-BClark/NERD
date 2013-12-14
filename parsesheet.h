#ifndef PARSESHEET_H
#define PARSESHEET_H

#include <QObject>
#include <xlsxworksheet.h>

class ParseSheet
{
public:
    ParseSheet();
    ~ParseSheet();
public slots:
    void selectSheet(int row);
    void setNextSheet();
    void setPrevSheet();
    void getCurrentRow(void);
    void getCurrentColumn(void);
    int getColumnCount(void);
    int getRowCount(void);

    QString getTitle(void);
    QString getValue(int row, int col);
    void setData(QXlsx::Worksheet page);
protected slots:
    void setCurrentSheet(int row);
private:
    int currentR;
    int currentC;
    QXlsx::Worksheet *sheet;
};

#endif // PARSESHEET_H
