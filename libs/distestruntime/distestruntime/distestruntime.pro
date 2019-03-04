DISTESTRUNTIME_LIBRARY_TYPE = staticlib

include(distestruntime.pri)

TEMPLATE = lib

RootDir=$$PWD/..

CONFIG += $${DISTESTRUNTIME_LIBRARY_TYPE}

TARGET = $$DISTESTRUNTIME_NAME
LIBS -= -l$$DISTESTRUNTIME_NAME

DEFINES+=QT_NO_DEBUG_OUTPUT

#QMAKE_CXXFLAGS_WARN_ON = -Wall -Wextra -Wno-attributes
#QMAKE_CXXFLAGS_WARN_OFF = -Wattributes
win32-msvc*:QMAKE_CXXFLAGS += -wd4267
win64-msvc*:QMAKE_CXXFLAGS += -wd4267

HEADERS += \
    distestruntime_global.hpp \
    distestruntime.hpp \
    testcaseruntime.hpp \
    testcasestep.hpp \
    testcompruntime.hpp

SOURCES += \
    testcaseruntime.cpp \
    testcasestep.cpp \
    testcompruntime.cpp

