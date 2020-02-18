QT     += testlib
QT     -= gui
CONFIG += testcase
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

RHAPSODY_TARGET = $$shadowed($$PWD)
include($$PWD/../../importrhapsody.pri)
include($$PWD/../../../dslparser/dslparser/dslparser.pri)

TARGET = tst_rhapsodyimport

SOURCES += tst_rhapsodyimport.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

copyexamples.commands = $(COPY_DIR) \"$$shell_path($$PWD/examples)\" \"$$shell_path($$shadowed($$PWD)/examples)\"
QMAKE_EXTRA_TARGETS += copyexamples
POST_TARGETDEPS += copyexamples
