TARGET = QSystemHotkey

QMAKE_DOCS = $$PWD/doc/qsystemhotkey.qdocconf

load(qt_module)

CONFIG += build_systemhotkey_lib
include(qsystemhotkey.pri)

QMAKE_TARGET_COMPANY = "Brandon Clark"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2013 CCi <bclark1@cci.edu>"
QMAKE_TARGET_DESCRIPTION = "Listen for system wide hotkey events."

