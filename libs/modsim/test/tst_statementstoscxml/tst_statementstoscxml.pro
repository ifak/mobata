QT     += testlib

QT       -= gui

include($$PWD/../../../modsim/modsim/modsim.pri)

TARGET = tst_statementstoscxml
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_statementstoscxml.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
