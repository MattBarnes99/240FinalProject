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



    return 0;
}
