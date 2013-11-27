TARGET = QtXlsx

QMAKE_DOCS = $$PWD/doc/qtxlsx.qdocconf

load(qt_module)

CONFIG += build_xlsx_lib
include(qtxlsx.pri)

#Define this macro if you want to run tests, so more AIPs will get exported.
#DEFINES += XLSX_TEST

QMAKE_TARGET_COMPANY = "Debao Zhang"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2013 Debao Zhang <hello@debao.me>"
QMAKE_TARGET_DESCRIPTION = ".Xlsx file wirter for Qt5"


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/release/ -lQt0Xlsxd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/debug/ -lQt0Xlsxd

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
