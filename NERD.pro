#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T07:56:44
#
#-------------------------------------------------

SUBDIRS = QtXlsx \
        QSystemHotkey

include(QtXlsx/xlsx/qtxlsx.pri)
include(QSystemHotkey/src/systemhotkey/qsystemhotkey.pri)

QT       += core gui

QT += widgets

TARGET = NERD
TEMPLATE = app


SOURCES += main.cpp\
        nerdmain.cpp \
    about.cpp \
    currentrecord.cpp \
    ssheet.cpp \
    wbook.cpp \
    parsecell.cpp \
    parserecord.cpp \
    parsesheet.cpp \
    parsebook.cpp \
    fileopen.cpp \
    excelmockwidget.cpp \
    parseexcel.cpp \
    navigate.cpp \
    navigatebuttons.cpp \
    systemfocuswidget.cpp \
    widget.cpp

HEADERS  += nerdmain.h \
    about.h \
    currentrecord.h \
    ssheet.h \
    wbook.h \
    parsecell.h \
    parserecord.h \
    parsesheet.h \
    parsebook.h \
    fileopen.h \
    excelmockwidget.h \
    parseexcel.h \
    navigate.h \
    navigatebuttons.h \
    systemfocuswidget.h \
    widget.h

FORMS    += nerdmain.ui \
    about.ui \
    currentrecord.ui \
    btnparse.ui \
    wbook.ui \
    fileopen.ui \
    navigatebuttons.ui \
    systemfocuswidget.ui \
    ssheet.ui

OTHER_FILES += \
    img/cci-horizontal-black-large.png \
    TODO \
    res.rc

RESOURCES += \
    res.qrc

RC_FILE = res.rc
