QT     += testlib
CONFIG += testcase

QT       -= gui

include($$PWD/../../remotecontrol.pri)

isEmpty(DISTESTRUNTIME_HOME) {
  DISTESTRUNTIME_HOME = $$PWD/../../../distestruntime
}
DISTESTRUNTIME_PRIFILE = $${DISTESTRUNTIME_HOME}/distestruntime/distestruntime.pri
requires(exists($${DISTESTRUNTIME_PRIFILE}))
include($${DISTESTRUNTIME_PRIFILE})

TARGET = tst_remotecontrol
CONFIG += console
CONFIG += testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    remotecontroltester.hpp \
    remotecontrolsut.hpp \
    sutadapter.hpp \
    testadapter.hpp

SOURCES += \
    tst_remotecontrol.cpp \
    remotecontroltester.cpp \
    remotecontrolsut.cpp \
    sutadapter.cpp \
    testadapter.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

## copy qjsonrpc dynamic libs to the right directory
#win32{
#  copyqjsonrpcdll.commands = $(COPY_DIR) \"$$QJSONRPC_LIBDIR\" \"$$OUT_PWD\"
#} else {
#  copyqjsonrpcdll.commands = $(COPY_DIR) $$QJSONRPC_LIBDIR/* $$OUT_PWD
#}
#QMAKE_EXTRA_TARGETS += copyqjsonrpcdll
#POST_TARGETDEPS += copyqjsonrpcdll
