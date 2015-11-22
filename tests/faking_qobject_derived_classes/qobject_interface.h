#ifndef QOBJECT_INTERFACE_H
#define QOBJECT_INTERFACE_H

#include <QObject>
#include <QString>

class QObjectInterface
{
public:
    virtual ~QObjectInterface() {}
    virtual QString objectName() = 0;
    virtual void setObjectName(const QString& name) = 0;
};

#endif  // QOBJECT_INTERFACE_H
