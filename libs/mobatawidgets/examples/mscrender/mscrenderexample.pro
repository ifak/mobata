QT       += core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../

MOBATA_LIBRARY_TYPE = staticlib
include($$RootDir/mobatawidgets.pri)
TEMPLATE = app

CONFIG(debug, debug|release){
TARGET = mscexampled
}
else{
TARGET = mscexample
}

SOURCES += main.cpp\
        mainwindow.cpp \
    msctabwidget.cpp

HEADERS  += mainwindow.hpp \
    msctabwidget.hpp

FORMS    += mainwindow.ui
