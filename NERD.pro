#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T07:56:44
#
#-------------------------------------------------

SUBDIRS = QtXlsx \
        QSystemHotkey \
        QExcelView

QT       += core gui
QT       += widgets

include(QtXlsx/xlsx/qtxlsx.pri)
include(QSystemHotkey/src/systemhotkey/qsystemhotkey.pri)
include(QExcelView/src/qexcelview/qexcelview.pri)

TARGET = NERD
TEMPLATE = app

SOURCES += main.cpp\
        nerdmain.cpp \
    about.cpp \
    currentrecord.cpp \
    parsecell.cpp \
    parserecord.cpp \
    parsesheet.cpp \
    parsebook.cpp \
    fileopen.cpp \
    parseexcel.cpp \
    navigate.cpp \
    navigatebuttons.cpp \
    systemfocuswidget.cpp

HEADERS  += nerdmain.h \
    about.h \
    currentrecord.h \
    parsecell.h \
    parserecord.h \
    parsesheet.h \
    parsebook.h \
    fileopen.h \
    parseexcel.h \
    navigate.h \
    navigatebuttons.h \
    systemfocuswidget.h

FORMS    += nerdmain.ui \
    about.ui \
    currentrecord.ui \
    btnparse.ui \
    fileopen.ui \
    navigatebuttons.ui \
    systemfocuswidget.ui

OTHER_FILES += \
    img/cci-horizontal-black-large.png \
    TODO \
    res.rc

RESOURCES += \
    res.qrc

RC_FILE = res.rc
