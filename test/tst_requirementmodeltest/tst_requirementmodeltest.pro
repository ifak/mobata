QT     += testlib
CONFIG += testcase

QT       -= gui

include($$PWD/../../mobata/mobata.pri)

TARGET = tst_requirementmodeltest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_requirementmodeltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
