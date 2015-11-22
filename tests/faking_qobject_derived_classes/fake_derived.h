#ifndef FAKE_DERIVED_H
#define FAKE_DERIVED_H

#include <QObject>
#include <iostream>

#include "fake_base.h"
#include "derived_interface.h"

class FakeDerived : public FakeBase, public DerivedInterface
{
    Q_OBJECT
public:

    // Methods from QObject.
    QString objectName() { return FakeBase::objectName(); }
    void setObjectName(const QString& name) { FakeBase::setObjectName(name); }

    // Methods from FakeBase.
    void foo() { FakeBase::foo(); }

    // Methods specific for FakeDerived.
    void bar() { std::cout << "FakeDerived::bar()" << std::endl; }
};

#endif  // FAKE_DERIVED_H
