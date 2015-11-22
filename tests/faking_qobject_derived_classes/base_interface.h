#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H

#include "qobject_interface.h"

#include <QObject>
#include <iostream>

class BaseInterface : public QObjectInterface
{
public:
    virtual ~BaseInterface() {}
    virtual void foo() = 0;
};

#endif  // BASE_INTERFACE_H
