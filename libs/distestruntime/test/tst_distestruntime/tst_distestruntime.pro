QT     += testlib

QT       -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

isEmpty(DISTESTRUNTIME_HOME) {
  DISTESTRUNTIME_HOME = $$PWD/../..
}
DISTESTRUNTIME_PRIFILE = $${DISTESTRUNTIME_HOME}/distestruntime/distestruntime.pri
requires(exists($${DISTESTRUNTIME_PRIFILE}))
include($${DISTESTRUNTIME_PRIFILE})

TEMPLATE = app

SOURCES +=  tst_distestruntimetestcase.cpp
