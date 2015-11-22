#ifndef FAKE_BASE_H
#define FAKE_BASE_H

#include <QObject>
#include <QString>
#include <iostream>

#include "base_interface.h"

class FakeBase : public QObject, public BaseInterface
{
    Q_OBJECT
public:

    // Methods from QObject.
    virtual QString objectName() { return QObject::objectName(); }
    virtual void setObjectName(const QString& name) { QObject::setObjectName(name); }

    // Methods specific for FakeBase.
    virtual ~FakeBase() {}
    virtual void foo() { std::cout << "FakeBase::foo()" << std::endl; }
};

#endif  // FAKE_BASE_H
