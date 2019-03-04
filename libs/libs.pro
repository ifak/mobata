exists($$PWD/../../mobata_libs.config){
  include($$PWD/../../mobata_libs.config)
}

isEmpty(MOBATA_DSLPARSER_LIB){
  MOBATA_DSLPARSER_LIB = yes
}
isEmpty(MOBATA_GRAPHLAYOUT_LIB){
  MOBATA_GRAPHLAYOUT_LIB = yes
}
isEmpty(MOBATA_MODSIM_LIB){
  MOBATA_MODSIM_LIB = yes
}
isEmpty(MOBATA_DISTESTRUNTIME_LIB){
  MOBATA_DISTESTRUNTIME_LIB = yes
}
isEmpty(MOBATA_MODTRACE_LIB){
  MOBATA_MODTRACE_LIB = yes
}

TEMPLATE  = subdirs

contains(MOBATA_DSLPARSER_LIB, yes){
  SUBDIRS += dslparser
}

contains(MOBATA_DISTESTRUNTIME_LIB, yes){
  SUBDIRS += distestruntime
}

contains(MOBATA_MODSIM_LIB, yes){
  SUBDIRS += modsim
  modsim.depends += dslparser
  modsim.depends += distestruntime
}

contains(MOBATA_GRAPHLAYOUT_LIB, yes){
  SUBDIRS += graphlayout
}

contains(MOBATA_MODTRACE_LIB, yes){
  SUBDIRS += modtrace
}

