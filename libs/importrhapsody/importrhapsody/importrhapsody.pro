IMPORTRHAPSODY_LIBRARY_TYPE = staticlib

RHAPSODY_TARGET = $$shadowed($$PWD)
include($$PWD/../importrhapsody.pri)

TEMPLATE = lib
CONFIG += $${IMPORTRHAPSODY_LIBRARY_TYPE}
TARGET = $$IMPORTRHAPSODY_NAME

win32-msvc*:QMAKE_CXXFLAGS += -wd4251 -wd4290 -wd4250

SOURCES += \
    comimportrhapsody.cpp \
    importrhapsodyutils.cpp \
    importrhapsodyelements.inl \
    importrhapsodyelements.cpp \
    importrhapsodyutils.inl \
    comimportrhapsodytree.cpp \
    importrhapsodyelementtree.cpp \
    comimportrhapsodyactiveinstance.cpp \
    importrhapsodyprop.cpp \
    importrhapsodyworker.cpp \
    importrhapsodylayout.cpp \
    importrhapsodylayout.inl

HEADERS += \
    comimportrhapsody.hpp \
    importrhapsodyutils.hpp \
    importrhapsody_global.hpp \
    importrhapsodyelements.hpp \
    comimportrhapsodytree.hpp \
    importrhapsodyelementtree.hpp \
    comimportrhapsodyactiveinstance.hpp \
    importrhapsodyprop.hpp \
    importrhapsodyworker.hpp \
    importrhapsodypointer.hpp \
    importrhapsodylayout.hpp

DISTFILES += \
    rhapsody_7-5.tlb \
    ImportLayoutReadMe.txt

RESOURCES += \
    importrhapsody.qrc
