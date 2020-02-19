#-------------------------------------------------
#
# Project created by QtCreator 2013-01-13T12:16:17
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../../

include($$RootDir/modeling/modeling.pri)
TEMPLATE = app

INCLUDEPATH += $$RootDir/modeling

win32-g++{
DESTDIR	= $$PWD/bin/mingw

QMAKE_LIBDIR += $$RootDir/lib/mingw
}
win32-msvc2010{
DESTDIR	= $$PWD/bin/msvc2010

QMAKE_LIBDIR += $$RootDir/lib/msvc2010

DEFINES += _SCL_SECURE_NO_WARNINGS
DEFINES += _CRT_SECURE_NO_WARNINGS
}
linux-g++{
DESTDIR	= $$PWD/bin/linux

QMAKE_LIBDIR += $$RootDir/lib/linux
}

CONFIG(debug, debug|release){
TARGET = compexampled
}
else{
TARGET = compexample
}

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.hpp

FORMS    += mainwindow.ui
