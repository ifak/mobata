PETRICHECK_LIBRARY_TYPE = staticlib

include(petricheck.pri)

TEMPLATE = lib
QT += script
CONFIG += $${PETRICHECK_LIBRARY_TYPE}
TARGET = $$PETRICHECK_NAME

DISTFILES += \
    petricheck.pri

HEADERS += \
    petrigenerator.hpp \
    markinghandler.h \
    petriexception.h \
    triggermessage.h \
    triggermessageparam.h



SOURCES += \
    petrigenerator.cpp \
    markinghandler.cpp \
    triggermessage.cpp \
    triggermessageparam.cpp


