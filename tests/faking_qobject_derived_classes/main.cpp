#include "base_interface.h"
#include "derived_interface.h"

#include "base.h"
#include "derived.h"

#include "fake_base.h"
#include "fake_derived.h"

#include <QString>

#include <iostream>

void f(QObject* obj)
{
    std::cout << "f(Object*) called with object " << obj->objectName().toStdString() << "." << std::endl;
}

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

    // Functions with QObject* parameters, not using the interface (works because both are QObject derived classes).
    Base* real_base_parameter1 = new Base();
    f(real_base_parameter1);
    FakeBase* fake_base_parameter1 = new FakeBase();
    f(fake_base_parameter1);

    // Functions with QObject* parameters, using the interface (does not work).
    BaseInterface* real_base_parameter2 = new Base();
    //f(real_base_parameter2);  // error
    BaseInterface* fake_base_parameter2 = new FakeBase();
    //f(fake_base_parameter2);  // error
}
