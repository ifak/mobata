QT     += testlib

QT       -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

#DEFINES+=QT_NO_DEBUG_OUTPUT

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

TEMPLATE = app

SOURCES +=  tst_simruntimetestcase.cpp \
    simruntimecontrollersutadapter.cpp

RESOURCES += \
    tst_simruntime.qrc

DISTFILES += \
    tst_ping.statemachine \
    tst_pong.statemachine

HEADERS += \
    simruntimecontrollersutadapter.hpp
