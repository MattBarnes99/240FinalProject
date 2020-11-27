#include "TrafficLight.h"
#include <iostream>

using namespace std;


int main(){
    cout << "Running through a for loop to make sure the light changes state the way it should using the decrement method" << endl;

    TrafficLight light = TrafficLight(LightColor::red, 5, 5, 5);

    for (int i = 0; i < 100; i++){
        light.print();
        light.decrement();
    }



    return 0;
}
