QT       += core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../

MOBATA_LIBRARY_TYPE = staticlib
include($$RootDir/mobatawidgets.pri)

TEMPLATE = app
TARGET = spenatexample

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.hpp

FORMS    +=
