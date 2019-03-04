QT     += testlib
CONFIG += testcase

QT       -= gui

TEMPLATE = app

include($$PWD/../../modtrace/modtrace.pri)

SOURCES += \
    tst_modtracetest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES +=   testdata.qrc
