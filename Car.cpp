#ifndef __Car_CPP__
#define __Car_CPP__


#include "Car.h"
#include <iostream>


//Constructor takes in Car type, direction size, and rightTurn decision
//
//Parameters:
    // CarType, Direction, int size, bool rightTurn)
//
Car::Car(Direction originalDirection, bool rightTurn): Vehicle(VehicleType::car, originalDirection, 2, rightTurn){}


//Destructor
Car::~Car(){}





#endif
