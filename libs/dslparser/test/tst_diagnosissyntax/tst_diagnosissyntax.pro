#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T12:08:35
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_diagnosissyntax
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_diagnosissyntax.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    complexexamples.qrc
