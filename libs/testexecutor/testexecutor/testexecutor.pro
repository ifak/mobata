TESTEXECUTOR_LIBRARY_TYPE = staticlib
include($$PWD/../testexecutor.pri)

TEMPLATE = lib

RootDir=$$PWD/..

CONFIG += $${TESTEXECUTOR_LIBRARY_TYPE}
TARGET = $$TESTEXECUTOR_NAME
LIBS -= -l$$TESTEXECUTOR_NAME

SOURCES += \
        vibnadapter.cpp \
        vibnfakeadapter.cpp \
        vibntestadapter.cpp \
        vibntestexecutor.cpp \
        testexecutortestcase.cpp \
        testexecutormodel.cpp

HEADERS += \
        testexecutor_global.h \
        vibnadapter.hpp \
        vibnfakeadapter.hpp \
        vibntestadapter.hpp \
        vibntestexecutor.hpp \
        testexecutortestcase.hpp \
        testexecutormodel.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}
