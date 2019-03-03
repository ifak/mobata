TEMPLATE = subdirs

SUBDIRS += graphlayout
SUBDIRS += examples
SUBDIRS += test


examples.depends += graphlayout
test.depends += graphlayout
