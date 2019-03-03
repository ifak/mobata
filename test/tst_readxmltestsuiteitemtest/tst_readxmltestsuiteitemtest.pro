QT     += testlib
CONFIG += testcase

QT       -= gui

include($$PWD/../../mobata/mobata.pri)

TARGET = tst_readxmltestsuiteitemtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_readxmltestsuiteitemtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    testdata.qrc
