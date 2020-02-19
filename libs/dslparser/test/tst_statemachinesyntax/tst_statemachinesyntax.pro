#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T12:08:35
#
#-------------------------------------------------

QT     += testlib
QT     -= gui
CONFIG += testcase
CONFIG += console
CONFIG -= app_bundle

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_statemachinesyntax

TEMPLATE = app


SOURCES += \
    tst_statemachinesyntax.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    complexexamples.qrc

DISTFILES +=
