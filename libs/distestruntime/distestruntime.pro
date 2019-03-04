TEMPLATE = subdirs

SUBDIRS += distestruntime
SUBDIRS += test

test.depends += distestruntime
