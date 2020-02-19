TEMPLATE = subdirs

SUBDIRS += modtrace
SUBDIRS += test

test.depends += modtrace
