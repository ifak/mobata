QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_importreader
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_importreader.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    importreader.qrc
