#include "Car.h"

#include "Wheel.h"

#include <iostream>

Car::Car()
{
    std::cout << "Car()" << std::endl;
    pWheel = new Wheel(); 
}

Car::~Car()
{
    std::cout << "~Car()" << std::endl;
    
    //delete pWheel;
    pWheel->deleteLater();
}
