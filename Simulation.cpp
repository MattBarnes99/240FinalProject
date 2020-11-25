#ifndef __SIMULATION_CPP__
#define __SIMULATION_CPP__

#include <iostream>
#include "Simulation.h"

using namespace std;



Simulation::Simulation(){}

Simulation::Simulation(Animator anim,ConfigParser config,Lane north, Lane south, Lane east, Lane west, TrafficLight NS, TrafficLight EW){}

Simulation::~Simulation(){}

void Simulation::run(){}

int main(){
    Animator anim(8);

    Intersection botRight;
    Intersection topRight;
    Intersection botLeft;
    Intersection topLeft;

    botRight.setNext(&topRight);
    botLeft.setNext(&topLeft);
    botLeft.setRight(&botRight);
    topLeft.setRight(&topRight);

    Lane northBound = Lane(8, &botRight, &topRight);
    Lane southBound = Lane(8, &topLeft, &botLeft);
    Lane eastBound = Lane(8, &botLeft, &botRight);
    Lane westBound = Lane(8, &topRight, &topLeft);

    Vehicle v1(VehicleType::car, Direction::east, 2, false);
    Vehicle v2(VehicleType::truck, Direction::east, 4, false);
    Vehicle v3(VehicleType::car, Direction::west, 2, false);
    Vehicle v4(VehicleType::suv, Direction::west, 3, false);
    Vehicle v5(VehicleType::car, Direction::north, 2, false);
    Vehicle v6(VehicleType::truck, Direction::north, 4, false);
    Vehicle v7(VehicleType::car, Direction::south, 2, false);
    Vehicle v8(VehicleType::suv, Direction::south, 3, false);

    
    //vector<VehicleBase*> veg = northBound.getVehicleVector();
    anim.setVehiclesNorthbound(northBound.getVehicleVector());
    anim.setVehiclesSouthbound(southBound.getVehicleVector());
    anim.setVehiclesEastbound(eastBound.getVehicleVector());
    anim.setVehiclesWestbound(westBound.getVehicleVector());

    anim.setLightNorthSouth(LightColor::red);
    anim.setLightEastWest(LightColor::green);

    anim.draw(1);

    v1.placeVehicle(northBound.getStart());

    anim.setVehiclesNorthbound(northBound.getVehicleVector());
    anim.setVehiclesSouthbound(southBound.getVehicleVector());
    anim.setVehiclesEastbound(eastBound.getVehicleVector());
    anim.setVehiclesWestbound(westBound.getVehicleVector());

    anim.setLightNorthSouth(LightColor::red);
    anim.setLightEastWest(LightColor::green);

    anim.draw(2);

    return 0;
}

#endif