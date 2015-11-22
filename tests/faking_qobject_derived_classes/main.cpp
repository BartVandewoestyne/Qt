#include "base_interface.h"
#include "derived_interface.h"

#include "base.h"
#include "derived.h"

#include "fake_base.h"
#include "fake_derived.h"

#include <QString>

#include <iostream>

int main()
{
    // The real stuff.
    BaseInterface* real_base = new Base();
    real_base->setObjectName("real_base");
    std::cout << real_base->objectName().toStdString() << std::endl;
    real_base->foo();

    DerivedInterface* real_derived = new Derived();
    real_derived->setObjectName("real_derived");
    std::cout << real_derived->objectName().toStdString() << std::endl;
    real_derived->foo();
    real_derived->bar();

    delete real_base;
    delete real_derived;

    // The fake stuff.
    BaseInterface* fake_base = new FakeBase();
    fake_base->setObjectName("fake_base");
    std::cout << fake_base->objectName().toStdString() << std::endl;
    fake_base->foo();

    DerivedInterface* fake_derived = new FakeDerived();
    fake_derived->setObjectName("fake_derived");
    std::cout << fake_derived->objectName().toStdString() << std::endl;
    fake_derived->foo();
    fake_derived->bar();

    delete fake_base;
    delete fake_derived;
}
