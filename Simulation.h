#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "Animator.h"
#include "VehicleBase.h"
#include "ConfigParser.h"
#include "Clock.h"
#include "TrafficLight.h"
#include "Lane.h"
#include "Vehicle.h"
#include "randomGen.h"
#include "Intersection.h"
#include "Section.h"
#include <iostream>

using namespace std;

class Simulation{

    private:

        int maxSimulatedTime;
        int numSecBeforeIntersection;
        int greenTimeNS;
        int yellowTimeNS;
        int greenTimeEW;
        int yellowTimeEW;
        double probNewVehNorth;
        double probNewVehSouth;
        double probNewVehEast;
        double probNewVehWest;
        double propCars;
        double propSuvs;
        double propTrucks;
        double propRightTurnCar;
        double propLeftTurnCar;
        double propRightTurnSuv;
        double propLeftTurnSuv;
        double propRightTurnTruck;
        double propLeftTurnTruck;

        Lane north;
        Lane south;
        Lane east;
        Lane west;

        TrafficLight NS;
        TrafficLight EW;


    public:
        
        Simulation(Animator,ConfigParser,Lane north, Lane south, Lane east, Lane west, TrafficLight NS, TrafficLight EW);

        Simulation();

        ~Simulation();

        void run();
    
};

#endif