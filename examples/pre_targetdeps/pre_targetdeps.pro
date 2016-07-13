myQmakeTarget.target = someMakefileTargetName
myQmakeTarget.depends = FORCE
myQmakeTarget.commands = @echo "Tralalalala"
QMAKE_EXTRA_TARGETS += myQmakeTarget
PRE_TARGETDEPS += someMakefileTargetName

TEMPLATE = app
CONFIG -= moc
INCLUDEPATH += .

SOURCES += pre_targetdeps.cpp
