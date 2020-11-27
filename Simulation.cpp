#ifndef __SIMULATION_CPP__
#define __SIMULATION_CPP__

#include <iostream>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(){}

Simulation::Simulation(ConfigParser config){
    //Setting all instance variables
    maxSimulatedTime = stoi(config.get("maximum_simulated_time"));
    numSecBeforeIntersection = stoi(config.get("number_of_sections_before_intersection"));
    greenTimeNS = stoi(config.get("green_north_south"));
    yellowTimeNS = stoi(config.get("yellow_north_south"));
    greenTimeEW = stoi(config.get("green_east_west"));
    yellowTimeEW = stoi(config.get("yellow_east_west"));
    probNewVehNorth = stod(config.get("prob_new_vehicle_northbound"));
    probNewVehSouth = stod(config.get("prob_new_vehicle_southbound"));
    probNewVehEast = stod(config.get("prob_new_vehicle_eastbound"));
    probNewVehWest = stod(config.get("prob_new_vehicle_westbound"));
    propCars = stod(config.get("proportion_of_cars"));
    propSuvs = stod(config.get("proportion_of_SUVs"));
    propTrucks = (1-propCars-propSuvs);
    propLeftTurnCar = stod(config.get("proportion_left_turn_cars"));
    propRightTurnCar = stod(config.get("proportion_right_turn_cars")) + propLeftTurnCar;
    propLeftTurnSuv = stod(config.get("proportion_left_turn_SUVs"));
    propRightTurnSuv = stod(config.get("proportion_right_turn_SUVs")) + propLeftTurnSuv;
    propLeftTurnTruck = stod(config.get("proportion_left_turn_trucks"));
    propRightTurnTruck = stod(config.get("proportion_right_turn_trucks")) + propLeftTurnTruck;
    randomGen rand = randomGen();
    this->rand = rand;
}

Simulation::~Simulation(){}

void Simulation::run(int seed){

    //create animator
    Animator anim(numSecBeforeIntersection);
    
    //create intersection sections
    Intersection botRight = Intersection();
    Intersection topRight = Intersection();
    Intersection botLeft = Intersection();
    Intersection topLeft = Intersection();

    //create lanes
    Lane northBound = Lane(numSecBeforeIntersection, Direction::north, &botRight, &topRight);
    Lane southBound = Lane(numSecBeforeIntersection, Direction::south, &topLeft, &botLeft);
    Lane eastBound = Lane(numSecBeforeIntersection, Direction::east, &botLeft, &botRight);
    Lane westBound = Lane(numSecBeforeIntersection, Direction::west, &topRight, &topLeft);

    //Create traffic lights
    TrafficLight ns = TrafficLight(LightColor::green, greenTimeNS, yellowTimeNS, (greenTimeEW + yellowTimeEW));
    TrafficLight ew = TrafficLight(LightColor::red, greenTimeEW, yellowTimeEW, (greenTimeNS + yellowTimeNS));

    //Set vehicles on the animator
    anim.setVehiclesNorthbound(northBound.getVehicleVector());
    anim.setVehiclesSouthbound(southBound.getVehicleVector());
    anim.setVehiclesEastbound(eastBound.getVehicleVector());
    anim.setVehiclesWestbound(westBound.getVehicleVector());

    //set seed of randomGen
    rand.setSeed(seed);

    //Create counter for game
    int t = 0;

    //create loop to simulate clock
    while(t<=maxSimulatedTime){
        
        //make vehicles for the lanes
        makeVehicle(&northBound,probNewVehNorth);
        makeVehicle(&southBound,probNewVehSouth);
        makeVehicle(&eastBound,probNewVehEast);
        makeVehicle(&westBound,probNewVehWest);

        //set the traffic lights
        anim.setLightNorthSouth(ns.getColor());
        anim.setLightEastWest(ew.getColor());

        //set the animator with the vector<vehicle*> lanes
        anim.setVehiclesNorthbound(northBound.getVehicleVector());
        anim.setVehiclesSouthbound(southBound.getVehicleVector());
        anim.setVehiclesEastbound(eastBound.getVehicleVector());
        anim.setVehiclesWestbound(westBound.getVehicleVector());
    }

}


void Simulation::makeVehicle(Lane* l, double probNewVeh){
    double newVeh = rand.get();
    double type = rand.get();
    double turn = rand.get();

    //Check if there is an open space available for the new vehicle in the lane
    if (l->openSpace()){

        //check if new vehicle will be made
        if (newVeh <= probNewVeh){
            //check if a car will be made
            if (type <= propCars){
                VehicleBase veh = VehicleBase(VehicleType::car,l->getDir(),2,false);
                l->placeVehicle(&veh);
            }
            //check if a suv will be made
            else if (type > propCars && type <= (propCars + propSuvs)){
                VehicleBase veh = VehicleBase(VehicleType::suv,l->getDir(),3,false);
                l->placeVehicle(&veh);
            }
            //otherwise a truck will be made
            else{
                VehicleBase veh = VehicleBase(VehicleType::truck,l->getDir(),4,false);
                l->placeVehicle(&veh);
            }
        }

        //set turn choice for car
        if (l->getStart()->getVehicle()->getVehicleType() == VehicleType::car && turn <= propRightTurnCar){
            l->getStart()->getVehicle()->setTurnChoice(true);
        }
        //set turn choice for suv
        else if (l->getStart()->getVehicle()->getVehicleType() == VehicleType::suv && turn > propRightTurnCar && turn <= propRightTurnSuv + propRightTurnCar){
            l->getStart()->getVehicle()->setTurnChoice(true);
        }
        //set turn choice for truck
        else if (l->getStart()->getVehicle()->getVehicleType() == VehicleType::truck && turn > propRightTurnCar + propRightTurnSuv){
            l->getStart()->getVehicle()->setTurnChoice(true);
        }

    }
}




int main(int argc,char* argv[]){
    
    //preprocessing stage
    ConfigParser config = ConfigParser(argv[1]);
    
    Simulation sim = Simulation(config);

    int seed = stoi(argv[2]);

    sim.run(seed);


    // Animator anim(8);

    // Intersection botRight = Intersection();
    // Intersection topRight = Intersection();
    // Intersection botLeft = Intersection();
    // Intersection topLeft = Intersection();

    // Lane northBound = Lane(8, Direction::north, &botRight, &topRight);
    // Lane southBound = Lane(8, Direction::south, &topLeft, &botLeft);
    // Lane eastBound = Lane(8, Direction::east, &botLeft, &botRight);
    // Lane westBound = Lane(8, Direction::west, &topRight, &topLeft);

    // VehicleBase v1 = VehicleBase(VehicleType::car, Direction::east, 2, false);
    // VehicleBase v2 = VehicleBase(VehicleType::truck, Direction::east, 4, false);
    // VehicleBase v3 = VehicleBase(VehicleType::car, Direction::west, 2, false);
    // VehicleBase v4 = VehicleBase(VehicleType::suv, Direction::west, 3, false);
    // VehicleBase v5 = VehicleBase(VehicleType::car, Direction::north, 2, false);
    // VehicleBase v6 = VehicleBase(VehicleType::truck, Direction::north, 4, false);
    // VehicleBase v7 = VehicleBase(VehicleType::car, Direction::south, 2, false);
    // VehicleBase v8 = VehicleBase(VehicleType::suv, Direction::south, 3, false);


    // anim.setVehiclesNorthbound(northBound.getVehicleVector());
    // anim.setVehiclesSouthbound(southBound.getVehicleVector());
    // anim.setVehiclesEastbound(eastBound.getVehicleVector());
    // anim.setVehiclesWestbound(westBound.getVehicleVector());

    // anim.setLightNorthSouth(LightColor::red);
    // anim.setLightEastWest(LightColor::green);

    // anim.draw(1);

    // northBound.placeVehicle(&v1);
    // southBound.placeVehicle(&v2);
    
    // anim.setVehiclesNorthbound(northBound.getVehicleVector());
    // anim.setVehiclesSouthbound(southBound.getVehicleVector());
    // anim.setVehiclesEastbound(eastBound.getVehicleVector());
    // anim.setVehiclesWestbound(westBound.getVehicleVector());

    // anim.setLightNorthSouth(LightColor::red);
    // anim.setLightEastWest(LightColor::green);

    // anim.draw(2);

    return 0;
}

#endif
