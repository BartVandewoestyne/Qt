TEMPLATE = app

CONFIG += console

HEADERS += BaseThread.h \
           FooThread.h \
           BarThread.h

SOURCES += BaseThread.cpp \
           FooThread.cpp \
           BarThread.cpp \
           datarace.cpp
