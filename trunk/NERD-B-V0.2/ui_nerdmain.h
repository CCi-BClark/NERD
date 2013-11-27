/********************************************************************************
** Form generated from reading UI file 'nerdmain.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NERDMAIN_H
#define UI_NERDMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NerdMain
{
public:
    QAction *menuOpen;
    QAction *menuExit;
    QAction *menuStart;
    QAction *menuStop;
    QAction *menuNextRecord;
    QAction *menuDocs;
    QAction *menuAbout;
    QAction *menuHomepage;
    QAction *menuPrevRecord;
    QAction *menuNextCell;
    QAction *menuPrevCell;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QGroupBox *grpFileInProgress;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labCurrent;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnOpen;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableData;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPrev;
    QPushButton *btnPrevCell;
    QPushButton *btnNextCell;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun;
    QMenu *menuHelp;

    void setupUi(QMainWindow *NerdMain)
    {
        if (NerdMain->objectName().isEmpty())
            NerdMain->setObjectName(QStringLiteral("NerdMain"));
        NerdMain->resize(305, 319);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NerdMain->sizePolicy().hasHeightForWidth());
        NerdMain->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/cci-small.png"), QSize(), QIcon::Normal, QIcon::Off);
        NerdMain->setWindowIcon(icon);
        menuOpen = new QAction(NerdMain);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuExit = new QAction(NerdMain);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        menuStart = new QAction(NerdMain);
        menuStart->setObjectName(QStringLiteral("menuStart"));
        menuStart->setEnabled(true);
        menuStop = new QAction(NerdMain);
        menuStop->setObjectName(QStringLiteral("menuStop"));
        menuStop->setEnabled(false);
        menuNextRecord = new QAction(NerdMain);
        menuNextRecord->setObjectName(QStringLiteral("menuNextRecord"));
        menuNextRecord->setEnabled(true);
        menuDocs = new QAction(NerdMain);
        menuDocs->setObjectName(QStringLiteral("menuDocs"));
        menuAbout = new QAction(NerdMain);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuHomepage = new QAction(NerdMain);
        menuHomepage->setObjectName(QStringLiteral("menuHomepage"));
        menuPrevRecord = new QAction(NerdMain);
        menuPrevRecord->setObjectName(QStringLiteral("menuPrevRecord"));
        menuPrevRecord->setEnabled(true);
        menuNextCell = new QAction(NerdMain);
        menuNextCell->setObjectName(QStringLiteral("menuNextCell"));
        menuNextCell->setEnabled(true);
        menuPrevCell = new QAction(NerdMain);
        menuPrevCell->setObjectName(QStringLiteral("menuPrevCell"));
        centralWidget = new QWidget(NerdMain);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        grpFileInProgress = new QGroupBox(centralWidget);
        grpFileInProgress->setObjectName(QStringLiteral("grpFileInProgress"));
        grpFileInProgress->setMinimumSize(QSize(200, 40));
        grpFileInProgress->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(grpFileInProgress);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 4);
        labCurrent = new QLabel(grpFileInProgress);
        labCurrent->setObjectName(QStringLiteral("labCurrent"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labCurrent->sizePolicy().hasHeightForWidth());
        labCurrent->setSizePolicy(sizePolicy1);
        labCurrent->setMinimumSize(QSize(0, 15));
        labCurrent->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(labCurrent);


        horizontalLayout->addWidget(grpFileInProgress);


        horizontalLayout_6->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 9);

        verticalLayout_2->addLayout(verticalLayout_3);

        btnOpen = new QPushButton(centralWidget);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        btnOpen->setMinimumSize(QSize(0, 25));
        btnOpen->setMaximumSize(QSize(100, 16777215));
        btnOpen->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(btnOpen);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 9, -1, 0);

        verticalLayout_2->addLayout(verticalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        tableData = new QTableWidget(centralWidget);
        tableData->setObjectName(QStringLiteral("tableData"));
        tableData->setEnabled(true);

        verticalLayout->addWidget(tableData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btnPrev = new QPushButton(centralWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        btnPrev->setMaximumSize(QSize(30, 16777215));
        btnPrev->setStyleSheet(QStringLiteral(""));
        btnPrev->setFlat(false);

        horizontalLayout_2->addWidget(btnPrev);

        btnPrevCell = new QPushButton(centralWidget);
        btnPrevCell->setObjectName(QStringLiteral("btnPrevCell"));
        btnPrevCell->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(btnPrevCell);

        btnNextCell = new QPushButton(centralWidget);
        btnNextCell->setObjectName(QStringLiteral("btnNextCell"));
        btnNextCell->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(btnNextCell);

        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setMaximumSize(QSize(30, 16777215));
        btnNext->setStyleSheet(QStringLiteral(""));
        btnNext->setFlat(false);

        horizontalLayout_2->addWidget(btnNext);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setMaximumSize(QSize(100, 16777215));
        btnStart->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(btnStart);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout);

        NerdMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NerdMain);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 305, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        menuRun->setEnabled(true);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        NerdMain->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuOpen);
        menuFile->addSeparator();
        menuFile->addAction(menuExit);
        menuRun->addAction(menuStart);
        menuRun->addAction(menuStop);
        menuRun->addSeparator();
        menuRun->addAction(menuNextRecord);
        menuRun->addAction(menuPrevRecord);
        menuRun->addSeparator();
        menuRun->addAction(menuNextCell);
        menuRun->addAction(menuPrevCell);
        menuHelp->addAction(menuDocs);
        menuHelp->addSeparator();
        menuHelp->addAction(menuAbout);
        menuHelp->addAction(menuHomepage);

        retranslateUi(NerdMain);

        QMetaObject::connectSlotsByName(NerdMain);
    } // setupUi

    void retranslateUi(QMainWindow *NerdMain)
    {
        NerdMain->setWindowTitle(QApplication::translate("NerdMain", "NERD", 0));
        menuOpen->setText(QApplication::translate("NerdMain", "Open File", 0));
        menuExit->setText(QApplication::translate("NerdMain", "Exit", 0));
        menuStart->setText(QApplication::translate("NerdMain", "Start", 0));
        menuStop->setText(QApplication::translate("NerdMain", "Stop", 0));
        menuNextRecord->setText(QApplication::translate("NerdMain", "Next Record", 0));
        menuDocs->setText(QApplication::translate("NerdMain", "Help Doc", 0));
        menuAbout->setText(QApplication::translate("NerdMain", "About", 0));
        menuHomepage->setText(QApplication::translate("NerdMain", "CCi Homepage", 0));
        menuPrevRecord->setText(QApplication::translate("NerdMain", "Prev Record", 0));
        menuNextCell->setText(QApplication::translate("NerdMain", "Next Cell", 0));
        menuPrevCell->setText(QApplication::translate("NerdMain", "Prev Cell", 0));
        grpFileInProgress->setTitle(QApplication::translate("NerdMain", "File In Process", 0));
        labCurrent->setText(QApplication::translate("NerdMain", "None", 0));
        btnOpen->setText(QApplication::translate("NerdMain", "Open File", 0));
        btnPrev->setText(QApplication::translate("NerdMain", "<<", 0));
        btnPrevCell->setText(QApplication::translate("NerdMain", "<", 0));
        btnNextCell->setText(QApplication::translate("NerdMain", ">", 0));
        btnNext->setText(QApplication::translate("NerdMain", ">>", 0));
        btnStart->setText(QApplication::translate("NerdMain", "Start", 0));
        menuFile->setTitle(QApplication::translate("NerdMain", "File", 0));
        menuRun->setTitle(QApplication::translate("NerdMain", "Run", 0));
        menuHelp->setTitle(QApplication::translate("NerdMain", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class NerdMain: public Ui_NerdMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NERDMAIN_H
