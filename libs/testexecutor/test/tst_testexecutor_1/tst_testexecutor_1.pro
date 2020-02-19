QT += testlib
QT += widgets
QT += concurrent

isEmpty(TESTEXECUTOR_LIB_PATH){
  TESTEXECUTOR_LIB_PATH = $$PWD/../../
}
TESTEXECUTOR_PRIFILE = $${TESTEXECUTOR_LIB_PATH}/testexecutor.pri
include($${TESTEXECUTOR_PRIFILE})

CONFIG += qt warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
  tst_testexecutortest.cpp

