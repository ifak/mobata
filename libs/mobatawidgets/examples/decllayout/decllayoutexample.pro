QT       += core gui widgets svg

RootDir=$$PWD/../../../

include($$RootDir/mobatawidgets/mobatawidgets.pri)
include($$RootDir/graphlayout/graphlayout/graphlayout.pri)

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.hpp

FORMS    += mainwindow.ui
