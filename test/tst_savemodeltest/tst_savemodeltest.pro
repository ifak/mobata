QT     += testlib
CONFIG += testcase

QT       -= gui

include($$PWD/../../mobata/mobata.pri)

TARGET = tst_savemodeltest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_savemodeltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
