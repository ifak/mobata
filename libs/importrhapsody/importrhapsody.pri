exists($$PWD/../../../mobata_libs.config){
  include($$PWD/../../../mobata_libs.config)
} else {
  MOBATA_IMPORTRHAPSODY_LIB = yes
}

IMPORTRHAPSODY_VERSION = 0.1.0

isEmpty(IMPORTRHAPSODY_LIBRARY_TYPE) {
    IMPORTRHAPSODY_LIBRARY_TYPE = staticlib
}

IMPORTRHAPSODY_PATH = $${PWD}
IMPORTRHAPSODY_INCLUDEPATH = $${IMPORTRHAPSODY_PATH}
IMPORTRHAPSODY_LIBDIR = $$shadowed($$PWD/importrhapsody)

CONFIG(debug, debug|release) {
  win*:IMPORTRHAPSODY_LIBDIR = $$IMPORTRHAPSODY_LIBDIR/debug
}else{
  win*:IMPORTRHAPSODY_LIBDIR = $$IMPORTRHAPSODY_LIBDIR/release
}

contains(IMPORTRHAPSODY_LIBRARY_TYPE, staticlib) {
    DEFINES += IMPORTRHAPSODY_LIBRARY_STATIC
} else {
    DEFINES += IMPORTRHAPSODY_LIBRARY
}

INCLUDEPATH += $${IMPORTRHAPSODY_INCLUDEPATH}
DEPENDPATH += $${IMPORTRHAPSODY_INCLUDEPATH}
QMAKE_LIBDIR += $${IMPORTRHAPSODY_LIBDIR}

CONFIG(debug, debug|release) {
  IMPORTRHAPSODY_NAME = importrhapsodyd
}else{
  IMPORTRHAPSODY_NAME = importrhapsody
}

LIBS += -l$$IMPORTRHAPSODY_NAME

isEmpty(MOBATA_LIB_PATH){
  MOBATA_LIB_PATH = $$PWD/../../mobata
}
MOBATA_PRIFILE = $${MOBATA_LIB_PATH}/mobata.pri
requires(exists($${MOBATA_PRIFILE}))
include($${MOBATA_PRIFILE})

isEmpty(GRAPHLAYOUT_LIB_PATH){
  GRAPHLAYOUT_LIB_PATH = $$PWD/../graphlayout
}
GRAPHLAYOUT_PRIFILE = $${GRAPHLAYOUT_LIB_PATH}/graphlayout.pri
requires(exists($${GRAPHLAYOUT_PRIFILE}))
include($${GRAPHLAYOUT_PRIFILE})


CONFIG(debug, debug|release) {
  TARGET_VAR="debug"
}
else{
  TARGET_VAR="release"
}

contains(MOBATA_IMPORTRHAPSODY_LIB, yes) {
  isEmpty(RHAPSODY_TARGET){
    warning("define path variable RHAPSODY Target in parent project file!")
  }
  else{
  RPATH = $$shell_path($$PWD\\rhapsody_7-5.tlh $$RHAPSODY_TARGET\\$$TARGET_VAR\\)
  CopyError = $$system(xcopy /q /y /i $$RPATH)
  }
}
