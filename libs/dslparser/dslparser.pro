TEMPLATE = subdirs
SUBDIRS += dslparser
SUBDIRS += test

test.depends += dslparser
