TRAFFICSIM_LIBRARY_TYPE = staticlib

include(trafficsim.pri)

TEMPLATE = lib

RootDir=$$PWD/..

CONFIG += $${TRAFFICSIM_LIBRARY_TYPE}

TARGET = $$TRAFFICSIM_NAME
LIBS -= -l$$TRAFFICSIM_NAME

#DEFINES+=QT_NO_DEBUG_OUTPUT

#QMAKE_CXXFLAGS_WARN_ON = -Wall -Wextra -Wno-attributes
#QMAKE_CXXFLAGS_WARN_OFF = -Wattributes
win32-msvc*:QMAKE_CXXFLAGS += -wd4267
win64-msvc*:QMAKE_CXXFLAGS += -wd4267

HEADERS += \
    Util/configreader.hpp \
    Util/errortracker.hpp \
    combuildtrafficsimmodel.hpp \
    comcreatetrafficsimproposals.hpp \
    edgeitem.hpp \
    intersectionitem.hpp \
    laneitem.hpp \
    lanetypeitem.hpp \
    phaseitem.hpp \
    sensoritem.hpp \
    stepitem.hpp \
    tlTransitionitem.hpp \
    trafficdistributionitem.hpp \
    trafficlightitem.hpp \
    trafficsim_global.hpp \
    trafficsimmodel.hpp \
    trafficsimmodellistener.hpp \
    vehiclemovementitem.hpp

SOURCES += \
    Util/configreader.cpp \
    Util/errortracker.cpp \
    combuildtrafficsimmodel.cpp \
    comcreatetrafficsimproposals.cpp \
    edgeitem.cpp \
    intersectionitem.cpp \
    laneitem.cpp \
    lanetypeitem.cpp \
    phaseitem.cpp \
    sensoritem.cpp \
    stepitem.cpp \
    tlTransitionitem.cpp \
    trafficdistributionitem.cpp \
    trafficlightitem.cpp \
    trafficsimmodel.cpp \
    trafficsimmodellistener.cpp \
    vehiclemovementitem.cpp

SUBDIRS += \
    trafficsim.pro

DISTFILES += \
    trafficsim.pri
