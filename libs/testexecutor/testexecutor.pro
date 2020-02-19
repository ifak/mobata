TEMPLATE = subdirs

SUBDIRS += \
  testexecutor \
  test

test.depends += testexecutor
