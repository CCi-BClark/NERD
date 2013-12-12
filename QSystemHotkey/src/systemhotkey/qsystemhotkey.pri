INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui gui-private
!build_systemhotkey_lib:DEFINES += SYSTEMHOTKEY_NO_LIB

HEADERS += $$PWD/qsystemhotkey.h \
    $$PWD/windows/targetver.h \
    $$PWD/windows/stdafx.h

SOURCES += $$PWD/qsystemhotkey.cpp \
    $$PWD/windows/stdafx.cpp
