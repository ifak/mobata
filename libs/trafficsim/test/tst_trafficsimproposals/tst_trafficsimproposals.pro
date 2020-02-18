#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T12:08:35
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

include($$PWD/../../trafficsim/trafficsim.pri)

TARGET = tst_trafficsimproposals
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_trafficsimproposals.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    example.qrc
