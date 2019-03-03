DSLPARSER_LIBRARY_TYPE = staticlib

include(modtrace.pri)

TEMPLATE = lib

RootDir=$$PWD/..

CONFIG += $${MODTRACE_LIBRARY_TYPE}

TARGET = $$MODTRACE_NAME
LIBS -= -l$$MODTRACE_NAME

#QMAKE_CXXFLAGS_WARN_ON = -Wall -Wextra -Wno-attributes
#QMAKE_CXXFLAGS_WARN_OFF = -Wattributes
win32-msvc*:QMAKE_CXXFLAGS += -wd4267
win64-msvc*:QMAKE_CXXFLAGS += -wd4267

HEADERS += \
    comcreatemodetrace.hpp \
    modtrace_global.hpp

SOURCES += \
    comcreatemodetrace.cpp


