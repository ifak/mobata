include(../petricheck/petricheck.pri)

QT       += testlib
QT += script
TARGET = tst_petrigeneration
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        tst_petrigeneration.cpp 

DEFINES += SRCDIR=\\\"$$PWD/\\\"

# TODO Name is currently just "test" - how to rename?
