QT       += core gui qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rhapsodyexample
TEMPLATE = app

isEmpty(GRAPHLAYOUT_LIB_PATH){
  GRAPHLAYOUT_LIB_PATH = $$PWD/../../../graphlayout
}

GRAPHLAYOUT_PRIFILE = $${GRAPHLAYOUT_LIB_PATH}/graphlayout.pri
requires(exists($${GRAPHLAYOUT_PRIFILE}))
include($${GRAPHLAYOUT_PRIFILE})

RHAPSODY_TARGET = $$shadowed($$PWD)
include($$PWD/../../importrhapsody.pri)

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    rhapsodyselectionview.cpp \
    rhapsodyimportproject.cpp \
    rhapsodymessage.cpp

HEADERS += \
    mainwindow.hpp \
    rhapsodyselectionview.hpp \
    rhapsodyimportproject.hpp \
    rhapsodymessage.hpp

FORMS += \
    mainwindow.ui \
    rhapsodyselectionview.ui \
    rhapsodyimportproject.ui

RESOURCES += \
    qmlRhapsodyExample.qrc

DISTFILES += \
    rhapsody_7-5.tlb
