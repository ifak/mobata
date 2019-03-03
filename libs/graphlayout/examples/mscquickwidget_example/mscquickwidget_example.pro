QT += qml quick

TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp

isEmpty(GRAPHLAYOUT_LIB_PATH){
  GRAPHLAYOUT_LIB_PATH = $$PWD/../../
}
GRAPHLAYOUT_PRIFILE = $${GRAPHLAYOUT_LIB_PATH}/graphlayout.pri
requires(exists($${GRAPHLAYOUT_PRIFILE}))
include($${GRAPHLAYOUT_PRIFILE})

HEADERS += \
    mainwindow.hpp
