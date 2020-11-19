#include "Vehicle.h"
#include "Car.h"
#include "Suv.h"

#include <iostream>

int main(){
    cout << "Testing Vehicle class" << endl;
    cout << "---------------------" << endl;

    cout << "Testing constructor" << endl;
    cout << "-------------------" << endl;
    bool turn = true;
    Vehicle veh = Vehicle(VehicleType::car,Direction::north,2,turn);

    cout << "Testing moveForward method" << endl;
    cout << "-------------------" << endl;
    Vehicle v1 = Vehicle(VehicleType::car,Direction::north,2,turn);
    //v1.moveForward();


    return 0;
}
