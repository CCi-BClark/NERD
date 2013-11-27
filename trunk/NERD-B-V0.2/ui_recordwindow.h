/********************************************************************************
** Form generated from reading UI file 'recordwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDWINDOW_H
#define UI_RECORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RecordWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labCurrentRecord;
    QLabel *labCurrentNum;
    QGroupBox *grpRecord;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listData;

    void setupUi(QDialog *RecordWindow)
    {
        if (RecordWindow->objectName().isEmpty())
            RecordWindow->setObjectName(QStringLiteral("RecordWindow"));
        RecordWindow->resize(321, 113);
        verticalLayout_2 = new QVBoxLayout(RecordWindow);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labCurrentRecord = new QLabel(RecordWindow);
        labCurrentRecord->setObjectName(QStringLiteral("labCurrentRecord"));

        horizontalLayout->addWidget(labCurrentRecord);

        labCurrentNum = new QLabel(RecordWindow);
        labCurrentNum->setObjectName(QStringLiteral("labCurrentNum"));

        horizontalLayout->addWidget(labCurrentNum);


        verticalLayout_2->addLayout(horizontalLayout);

        grpRecord = new QGroupBox(RecordWindow);
        grpRecord->setObjectName(QStringLiteral("grpRecord"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grpRecord->sizePolicy().hasHeightForWidth());
        grpRecord->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(grpRecord);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listData = new QListWidget(grpRecord);
        listData->setObjectName(QStringLiteral("listData"));
        listData->setAutoFillBackground(false);
        listData->setStyleSheet(QStringLiteral("background:transparent;"));
        listData->setFrameShape(QFrame::NoFrame);
        listData->setFrameShadow(QFrame::Plain);
        listData->setLineWidth(0);
        listData->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        listData->setAlternatingRowColors(true);
        listData->setSelectionBehavior(QAbstractItemView::SelectRows);
        listData->setSelectionRectVisible(true);

        horizontalLayout_2->addWidget(listData);


        verticalLayout_2->addWidget(grpRecord);


        retranslateUi(RecordWindow);

        QMetaObject::connectSlotsByName(RecordWindow);
    } // setupUi

    void retranslateUi(QDialog *RecordWindow)
    {
        RecordWindow->setWindowTitle(QApplication::translate("RecordWindow", "Current Record Tracker", 0));
        labCurrentRecord->setText(QApplication::translate("RecordWindow", "Current Record:", 0));
        labCurrentNum->setText(QString());
        grpRecord->setTitle(QApplication::translate("RecordWindow", "Record Information", 0));
    } // retranslateUi

};

namespace Ui {
    class RecordWindow: public Ui_RecordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDWINDOW_H
