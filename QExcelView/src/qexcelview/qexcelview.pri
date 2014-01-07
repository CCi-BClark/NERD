INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += core gui gui-private
!build_qexcelview_lib:DEFINES += QEXCELVIEW_NO_LIB

QT += widgets

HEADERS += $$PWD/excelview.h \
    $$PWD/ssheet.h \
    $$PWD/wbook.h

SOURCES += $$PWD/excelview.cpp \
    $$PWD/ssheet.cpp \
    $$PWD/wbook.cpp

FORMS    += $$PWD/wbook.ui \
    $$PWD/ssheet.ui
