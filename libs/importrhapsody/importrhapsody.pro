TEMPLATE = subdirs

SUBDIRS += importrhapsody
SUBDIRS += test
SUBDIRS += examples

test.depends += importrhapsody
examples.depends += importrhapsody
