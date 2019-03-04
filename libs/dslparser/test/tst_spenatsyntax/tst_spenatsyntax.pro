QT     += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_spenatsyntax
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_spenatsyntax.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
