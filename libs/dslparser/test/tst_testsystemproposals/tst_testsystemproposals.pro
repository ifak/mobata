QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_testsystemproposals
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_testsystemproposals.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    example.qrc
