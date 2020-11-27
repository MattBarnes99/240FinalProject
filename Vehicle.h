#ifndef __VEHICLE_H__
#define __VEHICLE_H__


#include "VehicleBase.h"
#include "TrafficLight.h"
#include "Section.fwd.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle : public VehicleBase {
    private:
        Section *head;
        Section *tail;
        int size;
        void setOccupied();
        int turningState = -1;
        bool turnChoice;
        bool greenLight = false;
        bool yellowLight = false;
        bool endOfRoad = false;
        Direction curDir;


    public:
        Vehicle(VehicleType type, Direction originalDirection, int size, bool rightTurn);
        ~Vehicle();

        Direction getDir();
        void setDir(Direction newDir);

        int getSize();
        bool getTurnChoice();

        void setHead(Section* head);
        void setTail(Section* tail);

        Section* getHead();
        Section* getTail();

        void setTurningState(int);
        int getTurningState();


};

#endif
