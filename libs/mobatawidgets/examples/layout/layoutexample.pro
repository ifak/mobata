QT       += core gui widgets svg

RootDir=$$PWD/../../../

include($$RootDir/mobatawidgets/mobatawidgets.pri)
include($$RootDir/graphlayout/graphlayout/graphlayout.pri)

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    extspenat.cpp \
    exttransition.cpp

HEADERS  += mainwindow.hpp \
    extspenat.hpp \
    exttransition.hpp

FORMS    += mainwindow.ui
