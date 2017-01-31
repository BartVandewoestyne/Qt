#ifndef CAR_H
#define CAR_H

#include "Car.h"

#include <QObject>

#include <iostream>

class Wheel;

class Car : public QObject
{
    Q_OBJECT

public:
    Car();
    ~Car();
private:
    Wheel* pWheel;
};

#endif  // CAR_H
