#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T12:08:35
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_diagnosisproposals
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_diagnosisproposals.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    example.qrc
