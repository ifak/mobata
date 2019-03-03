QT += testlib
QT += qml
QT += quick

isEmpty(GRAPHLAYOUT_LIB_PATH){
  GRAPHLAYOUT_LIB_PATH = $$PWD/../../
}
GRAPHLAYOUT_PRIFILE = $${GRAPHLAYOUT_LIB_PATH}/graphlayout.pri
requires(exists($${GRAPHLAYOUT_PRIFILE}))
include($${GRAPHLAYOUT_PRIFILE})

TARGET = tst_qmlgraphview

CONFIG += testcase
CONFIG += console
CONFIG += testcase

TEMPLATE = app

SOURCES += tst_tslayout.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
