QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_sutproposals
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_sutproposals.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
