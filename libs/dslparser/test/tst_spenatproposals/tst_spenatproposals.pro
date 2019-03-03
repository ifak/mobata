QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_spenatproposals
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_spenatproposals.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
