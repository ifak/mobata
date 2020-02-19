MODSIM_LIBRARY_TYPE = staticlib

include(modsim.pri)

TEMPLATE = lib

RootDir=$$PWD/..

CONFIG += $${MODSIM_LIBRARY_TYPE}

TARGET = $$MODSIM_NAME
LIBS -= -l$$MODSIM_NAME

#DEFINES+=QT_NO_DEBUG_OUTPUT

#QMAKE_CXXFLAGS_WARN_ON = -Wall -Wextra -Wno-attributes
#QMAKE_CXXFLAGS_WARN_OFF = -Wattributes
win32-msvc*:QMAKE_CXXFLAGS += -wd4267
win64-msvc*:QMAKE_CXXFLAGS += -wd4267

HEADERS += \
    comscxmlwriter.hpp \
    simmodel.hpp \
    simmodelworker.hpp \
    simruntimecontroller.hpp \
    simruntimeport.hpp \
    modsim_global.hpp \
    modsim.hpp \
    simruntime.hpp \
    combuildsimsystemmodel.hpp \
    comcreatesimsystemproposals.hpp \
    simsystem_types.hpp \
    simsystemitem.hpp \
    simsystemmodel.hpp \
    simsystemmodellistener.hpp \
    simmodelitem.hpp \
    simconfigitem.hpp \
    simconnectionitem.hpp

SOURCES += \
    comscxmlwriter.cpp \
    simmodel.cpp \
    simmodelworker.cpp \
    simruntimecontroller.cpp \
    simruntimeport.cpp \
    simruntime.cpp \
    combuildsimsystemmodel.cpp \
    comcreatesimsystemproposals.cpp \
    simsystemitem.cpp \
    simsystemmodel.cpp \
    simsystemmodellistener.cpp \
    simmodelitem.cpp \
    simconfigitem.cpp \
    simconnectionitem.cpp


