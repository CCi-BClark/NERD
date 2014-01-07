TARGET = QExcelView

QMAKE_DOCS = $$PWD/doc/qexcelview.qdocconf

load(qt_module)

CONFIG += build_qexcelview_lib
include(qexcelview.pri)

QMAKE_TARGET_COMPANY = "Brandon Clark"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2013 CCi <bclark1@cci.edu>"
QMAKE_TARGET_DESCRIPTION = "A mock excel view using QtabWidget and QTableWidget."

