TEMPLATE = app
TARGET = simpleptc

include($$PWD/../examples.pri)

QT += core network

SOURCES += \
    main.cpp \
    simpleptcservice.cpp \
    simpleptccomponent.cpp

HEADERS += \
    simpleptcservice.hpp \
    simpleptccomponent.hpp

defineReplace(copyToDir) {
    files = $$1
    DIR = $$2
    LINK =

    for(FILE, files) {
        LINK += $$QMAKE_COPY $$shell_path($$FILE) $$shell_path($$DIR) $$escape_expand(\\n\\t)
    }
    return($$LINK)
}

defineReplace(copyToBuilddir) {
    return($$copyToDir($$1, $$OUT_PWD))
}

contains(QJSONRPC_LIBRARY_TYPE,shared){
  win*{
    QMAKE_POST_LINK += $$copyToBuilddir($${QJSONRPC_LIBDIR}/$${IFAK_QJSONRPC_NAME}.dll)
  } else {
    QMAKE_POST_LINK += $$copyToBuilddir($${QJSONRPC_LIBDIR}/lib$${IFAK_QJSONRPC_NAME}.so)
    QMAKE_POST_LINK += $$copyToBuilddir($${QJSONRPC_LIBDIR}/lib$${IFAK_QJSONRPC_NAME}.so.1)
    QMAKE_POST_LINK += $$copyToBuilddir($${QJSONRPC_LIBDIR}/lib$${IFAK_QJSONRPC_NAME}.so.1.1)
    QMAKE_POST_LINK += $$copyToBuilddir($${QJSONRPC_LIBDIR}/lib$${IFAK_QJSONRPC_NAME}.so.1.1.0)
  }
}
