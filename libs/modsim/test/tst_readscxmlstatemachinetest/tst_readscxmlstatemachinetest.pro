QT     += testlib
CONFIG += testcase

QT       -= gui

STATECHARTS = \
    test.scxml\
    test2.scxml

isEmpty(MODSIM_HOME) {
  MODSIM_HOME = $$PWD/../..
}
MODSIM_PRIFILE = $${MODSIM_HOME}/modsim/modsim.pri
requires(exists($${MODSIM_PRIFILE}))
include($${MODSIM_PRIFILE})

isEmpty(DISTESTRUNTIME_HOME) {
  DISTESTRUNTIME_HOME = $$PWD/../../../distestruntime
}
DISTESTRUNTIME_PRIFILE = $${DISTESTRUNTIME_HOME}/distestruntime/distestruntime.pri
requires(exists($${DISTESTRUNTIME_PRIFILE}))
include($${DISTESTRUNTIME_PRIFILE})

TARGET = tst_readscxmlstatemachinetest
CONFIG -= app_bundle
CONFIG += console
CONFIG += statement
CONFIG += statemachine

TEMPLATE = app

SOURCES += tst_readscxmlstatemachinetest.cpp \
    scxmlsutadapter.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES +=   testdata.qrc

HEADERS += \
    scxmlsutadapter.hpp
