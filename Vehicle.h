#include "VehicleBase.h"
//#include "TrafficLight.h"
//#include "Section.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle : public VehicleBase {
    private:
        //Section *head;
        //Section *tail;
        int size;
        void setOccupied();
        bool turningState;
        bool turnChoice;
        bool greenLight = false;
        bool yellowLight = false;
        bool endOfRoad = false;
        Direction curDir;
        

    public:
        Vehicle(VehicleType type, Direction originalDirection, int size, bool rightTurn);
        ~Vehicle();
        void moveCheck();
        void moveForward(Vehicle *veh);
        void turnCheck();
        void turnRight(Vehicle *veh);

        Direction getDir();
        void setDir(Direction newDir);

        int getSize();

        bool getGreenLight();
        bool getYellowLight();
        void setTurningState(bool);

        //void setHead(Section *head);
        //void setTail(Section *tail);
        //Section * getHead();
        //Section * getTail();

        bool getTurningState();
        void removeVehicle(Vehicle *done);
    
        //void placeVehicle(Section *start);


};