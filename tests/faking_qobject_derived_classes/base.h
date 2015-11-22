#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QString>
#include <iostream>

#include "base_interface.h"

class Base : public QObject, public BaseInterface
{
    Q_OBJECT
public:

    // Methods from QObject.
    virtual QString objectName() { return QObject::objectName(); }
    virtual void setObjectName(const QString& name) { QObject::setObjectName(name); }

    // Methods specific for Base.
    virtual ~Base() {}
    virtual void foo() { std::cout << "Base::foo()" << std::endl; }
};

#endif  // BASE_H
