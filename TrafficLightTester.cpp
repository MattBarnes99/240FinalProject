#include "TrafficLight.h"
#include <iostream>

using namespace std;


int main(){
    cout << "Running through a for loop to make sure the light changes state the way it should using the decrement method" << endl;

    TrafficLight light = TrafficLight(LightColor::green, 5, 5);

    for (int i = 0; i < 100; i++){
        cout << static_cast<std::underlying_type<LightColor>::type>(light.getColor()) << endl;
        light.decrement();
    }



    return 0;
}
