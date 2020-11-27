#ifndef __VEHICLE_BASE_H__
#define __VEHICLE_BASE_H__

#include "Section.fwd.h"


// enum: see http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-enum
enum class Direction   {north, south, east, west};
enum class VehicleType {car, suv, truck};
enum class LightColor  {green, yellow, red};

class VehicleBase
{
   public:
      static int vehicleCount;

   private:

      int         vehicleID;
      VehicleType vehicleType;
      Direction   vehicleDirection;
      bool alreadyMoved;
      Section *head;
      Section *tail;
      int size;
      int turningState = 0;
      bool turnChoice;
      Direction curDir;

   public:
      
      VehicleBase(VehicleType type, Direction originalDirection, int size, bool rightTurn);
      VehicleBase(const VehicleBase& other);
      ~VehicleBase();

      inline int getVehicleID() const { return this->vehicleID; }

      inline VehicleType getVehicleType() const { return this->vehicleType; }
      inline Direction getVehicleOriginalDirection() const { return this->vehicleDirection; }

      void setAlreadyMoved(bool moved);
      bool getAlreadyMoved();

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
