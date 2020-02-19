QT     += testlib
CONFIG += testcase

QT       -= gui

include($$PWD/../../mobata/mobata.pri)

TARGET = tst_loadmodeltest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_loadmodeltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    testdata.qrc
