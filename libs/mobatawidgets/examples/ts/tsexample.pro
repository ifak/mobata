QT       += core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../

MOBATA_LIBRARY_TYPE = staticlib
include($$RootDir/mobatawidgets.pri)

TEMPLATE = app

CONFIG(debug, debug|release){
TARGET = tsexampled
}
else{
TARGET = tsexample
}

SOURCES += main.cpp\
        mainwindow.cpp \
    testcasetabwidget.cpp

HEADERS  += mainwindow.hpp \
    testcasetabwidget.hpp

FORMS    += mainwindow.ui
