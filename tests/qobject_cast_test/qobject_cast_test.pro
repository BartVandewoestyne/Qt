TEMPLATE = app

CONFIG += console

# Disable or enable RTTI.  With RTTI disabled, qobject_cast still works, but
# dynamic_cast is no longer available.
#
# Note: CONFIG -= rtti probably does not disable RTTI (see bug
#       report at https://bugreports.qt.io/browse/QTBUG-803), so
#       we disable it using QMAKE_CXXFLAGS.
#CONFIG -= rtti
#QMAKE_CXXFLAGS += -fno-rtti

HEADERS += mywidget.h
SOURCES += main.cpp
