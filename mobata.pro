TEMPLATE = subdirs
SUBDIRS += \
    3rd \
    mobata \
    libs

SUBDIRS += test

libs.depends += 3rd mobata
test.depends += 3rd mobata libs
