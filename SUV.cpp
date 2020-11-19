#ifndef __SUV_CPP__
#define __SUV_CPP__


#include "Suv.h"
#include <iostream>


//Constructor takes in Suv type, direction size, and rightTurn decision
//
//Parameters:
    // SuvType, Direction, int size, bool rightTurn)
//
Suv::Suv(Direction originalDirection, bool rightTurn): Vehicle(VehicleType::suv, originalDirection, 2, rightTurn){}


//Destructor
Suv::~Suv(){}



#endif
