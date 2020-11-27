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

        //draw animation
        anim.draw(t);

        //user increment
        cin.get(in);

        //parameters for advance()
        LightColor NScolor = ns.getColor();
        LightColor EWcolor = ew.getColor();
        int NSyellow = ns.getYellowTimeLeft();
        int EWyellow = ew.getYellowTimeLeft();

        //advance vehicles in all lanes
        northBound.advance(NScolor, NSyellow);
        southBound.advance(NScolor, NSyellow);
        eastBound.advance(EWcolor, EWyellow);
        westBound.advance(EWcolor, EWyellow);

        //reset alreadyMoved booleans for all vehicles
        northBound.resetMoveBool();
        southBound.resetMoveBool();
        eastBound.resetMoveBool();
        westBound.resetMoveBool();

        //decrement TrafficLights
        ns.decrement();
        ew.decrement();        

        //increment counter
        t++;
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
                VehicleBase* veh = new VehicleBase(VehicleType::car,l->getDir(),2,false);
                l->placeVehicle(veh);
            }
            //check if a suv will be made
            else if (type > propCars && type <= (propCars + propSuvs)){
                VehicleBase* veh = new VehicleBase(VehicleType::suv,l->getDir(),3,false);
                l->placeVehicle(veh);
            }
            //otherwise a truck will be made
            else{
                VehicleBase* veh = new VehicleBase(VehicleType::truck,l->getDir(),4,false);
                l->placeVehicle(veh);
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
}




int main(int argc,char* argv[]){
    
    ConfigParser config = ConfigParser(argv[1]);
    
    Simulation sim = Simulation(config);

    int seed = stoi(argv[2]);

    sim.run(seed);

    return 0;
}

#endif
