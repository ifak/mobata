QT       += core gui svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootDir=$$PWD/../../

MOBATAWIDGETS_LIBRARY_TYPE = staticlib
include($$RootDir/mobatawidgets.pri)

TEMPLATE = app
TARGET = compexample

SOURCES += main.cpp\
        mainwindow.cpp \
        systemeditview.cpp

HEADERS  += mainwindow.hpp \
            systemeditview.hpp

FORMS    +=
