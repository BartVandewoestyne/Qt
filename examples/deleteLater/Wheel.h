#ifndef WHEEL_H
#define WHEEL_H

#include <QObject>

#include <iostream>

class Wheel : public QObject
{
    Q_OBJECT

public:
    Wheel();
    ~Wheel();
};

#endif  // WHEEL_H
