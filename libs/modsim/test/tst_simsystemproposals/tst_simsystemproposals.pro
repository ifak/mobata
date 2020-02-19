QT     += testlib

QT       -= gui

include($$PWD/../../../modsim/modsim/modsim.pri)

TARGET = tst_simsystemsyntax
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_simsystemproposals.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    example.qrc
