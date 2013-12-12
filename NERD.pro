#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T07:56:44
#
#-------------------------------------------------

SUBDIRS = QtXlsx \
        QSystemHotkey

include(QtXlsx/src/xlsx/qtxlsx.pri)
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
    parsefile.cpp \
    parsesheet.cpp

HEADERS  += nerdmain.h \
    about.h \
    currentrecord.h \
    ssheet.h \
    wbook.h \
    parsecell.h \
    parserecord.h \
    parsefile.h \
    parsesheet.h

FORMS    += nerdmain.ui \
    about.ui \
    currentrecord.ui \
    btnparse.ui \
    ssheet.ui \
    wbook.ui

OTHER_FILES += \
    img/cci-horizontal-black-large.png \
    TODO \
    res.rc

RESOURCES += \
    res.qrc

RC_FILE = res.rc
