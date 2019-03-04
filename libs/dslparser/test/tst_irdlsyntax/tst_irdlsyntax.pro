#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T12:08:35
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_irdlsyntax
CONFIG += console
CONFIG += irdl
CONFIG -= app_bundle
CONFIG += testcase

TEMPLATE = app


SOURCES += \
    tst_irdlsyntax.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    complexexamples.qrc
