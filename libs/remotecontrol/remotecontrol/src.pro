REMOTECONTROL_LIBRARY_TYPE = staticlib
include(../remotecontrol.pri)

TEMPLATE = lib
QT -= gui

CONFIG += $$REMOTECONTROL_LIBRARY_TYPE
TARGET = $$REMOTECONTROL_NAME

HEADERS += \
    remotecontrolstatemachine.hpp \
    remotecontrol_global.hpp \
    remotecontrolservice.hpp \
    remotecontrol.hpp \
    remotecontroluser.hpp \
    remotecontroluserservice.hpp \
    remotecontrolfunctors.hpp \
    remoteconnectionmanager.hpp \
    remotecomponent.hpp \
    remoteport.hpp \
    controlport.hpp \
    remotecontrolstatemachineqml.hpp


SOURCES += \
    remotecontrolstatemachine.cpp \
    remotecontrol.cpp \
    remotecontrolservice.cpp \
    remotecontroluser.cpp \
    remotecontroluserservice.cpp \
    remotecontrolfunctors.cpp \
    remoteconnectionmanager.cpp \
    remotecomponent.cpp \
    remotecontrolstatemachineqml.cpp

DISTFILES += \
    remotecontrolstatemachine.qml \
    ../remotecontrol.pri

RESOURCES += \
    remotecontrol.qrc

STATECHARTS += \
    scxmlrcstatemachine.scxml
