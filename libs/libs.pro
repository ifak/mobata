exists($$PWD/../../mobata_libs.config){
  include($$PWD/../../mobata_libs.config)
}

isEmpty(MOBATA_DSLPARSER_LIB){
  MOBATA_DSLPARSER_LIB = yes
}
isEmpty(MOBATA_MOBATAWIDGETS_LIB){
  MOBATA_MOBATAWIDGETS_LIB = yes
}
isEmpty(MOBATA_GRAPHLAYOUT_LIB){
  MOBATA_GRAPHLAYOUT_LIB = yes
}
isEmpty(MOBATA_PETRICHECK_LIB){
  MOBATA_PETRICHECK_LIB = no
}
isEmpty(MOBATA_REMOTECONTROL_LIB){
  MOBATA_REMOTECONTROL_LIB = no
}
isEmpty(MOBATA_IMPORTRHAPSODY_LIB){
  MOBATA_IMPORTRHAPSODY_LIB = yes
}
isEmpty(MOBATA_MODSIM_LIB){
  MOBATA_MODSIM_LIB = yes
}
isEmpty(MOBATA_DISTESTRUNTIME_LIB){
  MOBATA_DISTESTRUNTIME_LIB = yes
}
isEmpty(MOBATA_TRAFFICSIM_LIB){
  MOBATA_TRAFFICSIM_LIB = no #should be removed
}

isEmpty(MOBATA_MODTRACE_LIB){
  MOBATA_MODTRACE_LIB = yes
}

isEmpty(TEST_EXECUTOR){
  win32: TEST_EXECUTOR = yes
  else: TEST_EXECUTOR = no
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

contains(MOBATA_MOBATAWIDGETS_LIB, yes){
  SUBDIRS += mobatawidgets
}

contains(MOBATA_GRAPHLAYOUT_LIB, yes){
  SUBDIRS += graphlayout
  graphlayout.depends += mobatawidgets
}

contains(MOBATA_PETRICHECK_LIB, yes){
  SUBDIRS += petricheck
}

contains(MOBATA_REMOTECONTROL_LIB, yes){
  SUBDIRS += remotecontrol
}

contains(MOBATA_MODTRACE_LIB, yes){
  SUBDIRS += modtrace
}

contains(MOBATA_IMPORTRHAPSODY_LIB, yes){
  win*-msvc*:SUBDIRS += importrhapsody
  win*-msvc*:importrhapsody.depends += graphlayout
  win*-msvc*:importrhapsody.depends += dslparser
}

contains(MOBATA_TRAFFICSIM_LIB, yes){
  SUBDIRS += trafficsim
  trafficsim.depends += dslparser
}

contains(TEST_EXECUTOR, yes){
  SUBDIRS +=  testexecutor
}




