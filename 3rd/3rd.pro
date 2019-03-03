exists($$PWD/../../mobata_libs.config){
  include($$PWD/../../mobata_libs.config)
}

isEmpty(MOBATA_ANTLR4CPP_LIB){
  MOBATA_ANTLR4CPP_LIB = yes
}

TEMPLATE  = subdirs

contains(MOBATA_ANTLR4CPP_LIB, yes){
  SUBDIRS += antlr4-cpp
}
