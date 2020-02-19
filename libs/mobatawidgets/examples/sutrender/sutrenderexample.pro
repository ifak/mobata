QT       += core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../

MOBATA_LIBRARY_TYPE = staticlib
include($$RootDir/mobatawidgets.pri)
TEMPLATE = app

CONFIG(debug, debug|release){
TARGET = sutrenderexampled
}
else{
TARGET = sutrenderexample
}

SOURCES += main.cpp\
        mainwindow.cpp \
    configdelegate.cpp \
    settings.cpp

HEADERS  += mainwindow.hpp \
    configdelegate.h \
    settings.h \
    settings.hpp

FORMS    += mainwindow.ui
