QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_sutsyntax
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_sutsyntax.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
