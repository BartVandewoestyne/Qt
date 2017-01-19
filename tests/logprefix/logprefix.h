#include <iostream>

#include <QDebug>
#include <QObject>
#include <QString>

class A : public QObject {

    Q_OBJECT

public:
    void methodA() { qDebug() << mfGetLogPrefix() << ": methodA()"; }
    virtual ~A() {}

protected:
    virtual QString mfGetLogPrefix() {
        return metaObject()->className();
    }
};

class B : public A {

    Q_OBJECT

public:
    void methodB() { qDebug() << mfGetLogPrefix() << ": methodB()"; }
};

class C : public B {

    Q_OBJECT

public:
    void methodC() { qDebug() << mfGetLogPrefix() << ": methodC()"; }
};
