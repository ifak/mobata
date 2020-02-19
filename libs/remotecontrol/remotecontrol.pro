TEMPLATE = subdirs

SUBDIRS += remotecontrol
SUBDIRS += examples
#SUBDIRS += tests

remotecontrol.file = $$PWD/remotecontrol/src.pro

examples.depends += remotecontrol
#tests.depends += remotecontrol
