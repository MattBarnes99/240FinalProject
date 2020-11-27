#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "Animator.h"
#include "VehicleBase.h"
#include "ConfigParser.h"
#include "TrafficLight.h"
#include "Lane.h"
#include "randomGen.h"
#include "Intersection.h"
#include "Section.h"
#include <iostream>

using namespace std;

class Simulation{

    private:

        int seed;
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
        randomGen rand;

    public:
        
        Simulation(ConfigParser);
        Simulation();
        ~Simulation(); 
        void run(int seed);
        void makeVehicle(Lane*,double);
};

#endif
