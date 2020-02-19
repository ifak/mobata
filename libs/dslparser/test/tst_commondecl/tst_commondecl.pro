QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_commonsyntax
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_commondecl.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
