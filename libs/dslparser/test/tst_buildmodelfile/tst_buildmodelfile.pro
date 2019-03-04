TEMPLATE = app

QT += testlib
QT -= gui

include($$PWD/../../dslparser/dslparser.pri)

TARGET = tst_buildmodelfile
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

SOURCES += \
    tst_buildmodelfile.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    test_models.qrc
