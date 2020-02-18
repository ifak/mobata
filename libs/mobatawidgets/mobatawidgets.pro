TEMPLATE = subdirs

SUBDIRS += mobatawidgets examples

mobatawidgets.file = $$PWD/mobatawidgets/src.pro

examples.depends += mobatawidgets
