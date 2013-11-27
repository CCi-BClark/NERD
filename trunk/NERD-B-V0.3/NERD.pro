#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T07:56:44
#
#-------------------------------------------------

SUBDIRS = src

include(src/src/xlsx/qtxlsx.pri)

QT       += core gui

QT += widgets

TARGET = NERD
TEMPLATE = app


SOURCES += main.cpp\
        nerdmain.cpp \
    recordwindow.cpp \
    aboutwindow.cpp \
    stdafx.cpp \
    systemhotkey.cpp \
    spreadsheet.cpp

HEADERS  += nerdmain.h \
    recordwindow.h \
    aboutwindow.h \
    stdafx.h \
    targetver.h \
    systemhotkey.h \
    spreadsheet.h

FORMS    += nerdmain.ui \
    recordwindow.ui \
    aboutwindow.ui \
    spreadsheet.ui

OTHER_FILES += \
    img/cci-horizontal-black-large.png \
    img/arrowright.gif \
    img/arrowdown.gif \
    TODO \
    res.rc

RESOURCES += \
    res.qrc

RC_FILE = res.rc
