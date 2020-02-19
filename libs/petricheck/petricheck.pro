TEMPLATE = subdirs
SUBDIRS += \
    petricheck \
    test

test.depends += petricheck
