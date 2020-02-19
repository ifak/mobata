#-------------------------------------------------
#
# Project created by QtCreator 2013-01-13T12:16:17
#
#-------------------------------------------------

QT       += core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../../

MOBATA_LIBRARY_TYPE = staticlib
include($$RootDir/mobatawidgets.pri)

TEMPLATE = app

CONFIG(debug, debug|release){
TARGET = graphexampled
}
else{
TARGET = graphexample
}

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.hpp

FORMS    += mainwindow.ui
