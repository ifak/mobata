TEMPLATE = app
include($$PWD/../../mobata/mobata.pri)

QT      += testlib
CONFIG  += testcase
CONFIG  += console
CONFIG  -= app_bundle

TARGET   = tst_statemachinetospenat
SOURCES += tst_statemachinetospenat.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    testdata.qrc
