#pragma once

#include <QtCore/qglobal.h>

#if defined(MOBATA_LIBRARY)
#  define MOBATASHARED_EXPORT Q_DECL_EXPORT
#elif(MOBATA_LIBRARY_STATIC)
#  define MOBATASHARED_EXPORT
#else
#  define MOBATASHARED_EXPORT Q_DECL_IMPORT
#endif
