TEMPLATE = subdirs

SUBDIRS += trafficsim
SUBDIRS += test

test.depends += trafficsim
