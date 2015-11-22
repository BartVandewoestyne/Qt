TEMPLATE = app

TARGET = faking_qobject_derived_classes

CONFIG += console

HEADERS = base.h \
          fake_base.h \
          derived.h \
          fake_derived.h

SOURCES = main.cpp
