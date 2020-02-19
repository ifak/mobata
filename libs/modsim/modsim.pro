TEMPLATE = subdirs

SUBDIRS += modsim
SUBDIRS += test

test.depends += modsim
