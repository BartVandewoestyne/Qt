#include "Foo.h"

#include <iostream>
#include <QDebug>

int main()
{
    qDebug() << "Foo::staticMetaObject.className() = "
             << Foo::staticMetaObject.className();
}
