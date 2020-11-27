#ifndef __SIMULATION_CPP__
#define __SIMULATION_CPP__

#include <iostream>
#include "Simulation.h"

using namespace std;



Simulation::Simulation(){}

Simulation::Simulation(Animator anim,ConfigParser config, Lane north, Lane south, Lane east, Lane west, TrafficLight NS, TrafficLight EW){}

Simulation::~Simulation(){}

void Simulation::run(){}

int main(){
    Animator anim(8);

    Intersection botRight = Intersection();
    Intersection topRight = Intersection();
    Intersection botLeft = Intersection();
    Intersection topLeft = Intersection();


    Lane northBound = Lane(8, Direction::north, &botRight, &topRight);
    Lane southBound = Lane(8, Direction::south, &topLeft, &botLeft);
    Lane eastBound = Lane(8, Direction::east, &botLeft, &botRight);
    Lane westBound = Lane(8, Direction::west, &topRight, &topLeft);



    VehicleBase v1 = VehicleBase(VehicleType::car, Direction::east, 2, false);
    VehicleBase v2 = VehicleBase(VehicleType::truck, Direction::east, 4, false);
    VehicleBase v3 = VehicleBase(VehicleType::car, Direction::west, 2, false);
    VehicleBase v4 = VehicleBase(VehicleType::suv, Direction::west, 3, false);
    VehicleBase v5 = VehicleBase(VehicleType::car, Direction::north, 2, false);
    VehicleBase v6 = VehicleBase(VehicleType::truck, Direction::north, 4, false);
    VehicleBase v7 = VehicleBase(VehicleType::car, Direction::south, 2, false);
    VehicleBase v8 = VehicleBase(VehicleType::suv, Direction::south, 3, false);


    anim.setVehiclesNorthbound(northBound.getVehicleVector());
    anim.setVehiclesSouthbound(southBound.getVehicleVector());
    anim.setVehiclesEastbound(eastBound.getVehicleVector());
    anim.setVehiclesWestbound(westBound.getVehicleVector());

    anim.setLightNorthSouth(LightColor::red);
    anim.setLightEastWest(LightColor::green);

    anim.draw(1);

    northBound.placeVehicle(&v1);
    southBound.placeVehicle(&v2);
    
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
