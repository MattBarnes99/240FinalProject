#include "VehicleBase.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Testing Vehicle class" << endl;
    cout << "---------------------" << endl;

    cout << "Testing constructor" << endl;
    cout << "-------------------" << endl;
    bool turn = true;
    VehicleBase veh = VehicleBase(VehicleType::car,Direction::north,2,turn);



    return 0;
}
