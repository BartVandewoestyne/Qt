# On Linux, this works with make.
#
# On Windows, this works with nmake, but fails with msbuild (see also [2]).
#
# References:
#
#   [1] http://doc.qt.io/qt-4.8/qmake-environment-reference.html#customizing
#   [2] http://stackoverflow.com/questions/10107289/qmake-qmake-extra-targets-with-vs2010

myQmakeTarget.target = someMakefileTargetName
myQmakeTarget.depends = FORCE
myQmakeTarget.commands = @echo "Doing some stuff before compiling the target..."
QMAKE_EXTRA_TARGETS += myQmakeTarget
PRE_TARGETDEPS += someMakefileTargetName

SOURCES += pre_targetdeps.cpp
