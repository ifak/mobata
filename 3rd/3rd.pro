exists($$PWD/../../mobata_libs.config){
  include($$PWD/../../mobata_libs.config)
}

isEmpty(MOBATA_ANTLR4CPP_LIB){
  MOBATA_ANTLR4CPP_LIB = yes
}

isEmpty(MOBATA_IFAKQJSONRPC_LIB){
  MOBATA_IFAKQJSONRPC_LIB = no
}

isEmpty(VIBN_MQTT){
  VIBN_MQTT = no
}

TEMPLATE  = subdirs

contains(MOBATA_ANTLR4CPP_LIB, yes){
  SUBDIRS += antlr4-cpp
}

contains(MOBATA_IFAKQJSONRPC_LIB, yes){
  SUBDIRS += ifak_qjsonrpc
}

contains(VIBN_MQTT, yes){
  SUBDIRS += vibn_mqtt
}

