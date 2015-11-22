#ifndef DERIVED_H
#define DERIVED_H

#include <QObject>
#include <iostream>

#include "base.h"
#include "derived_interface.h"

class Derived : public Base, public DerivedInterface
{
    Q_OBJECT
public:

    // Methods from QObject.
    QString objectName() { return Base::objectName(); }
    void setObjectName(const QString& name) { Base::setObjectName(name); }

    // Methods from Base.
    void foo() { Base::foo(); }

    // Methods specific for Derived.
    void bar() { std::cout << "Derived::bar()" << std::endl; }
};

#endif  // DERIVED_H
