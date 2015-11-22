#ifndef DERIVED_INTERFACE_H
#define DERIVED_INTERFACE_H

#include <QObject>
#include <iostream>

class DerivedInterface : public BaseInterface
{
public:
    virtual ~DerivedInterface() {}
    virtual void bar() = 0;
};

#endif  // DERIVED_INTERFACE_H
