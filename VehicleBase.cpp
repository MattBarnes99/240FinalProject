#ifndef __VEHICLE_BASE_CPP__
#define __VEHICLE_BASE_CPP__

#include "VehicleBase.h"

int VehicleBase::vehicleCount = 0;

VehicleBase::VehicleBase(VehicleType type, Direction originalDirection, int size, bool rightTurn)
    : vehicleID(VehicleBase::vehicleCount++), 
      vehicleType(type),
      vehicleDirection(originalDirection),
      size{size}, 
      turnChoice{rightTurn}
{}

VehicleBase::VehicleBase(const VehicleBase& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection)
{}

VehicleBase::~VehicleBase() {}


//getDir returns the current direction of the vehicle
//
Direction VehicleBase::getDir(){return curDir;}


//setDir sets the current direction to the new direction
//
//Parameter - Direction newDir
//
void VehicleBase::setDir(Direction newDir){curDir = newDir;}


//getSize returns the size of the vehicle
int VehicleBase::getSize(){return size;}


//getTurnChoice returns the bool turnChoice of the vehicle
bool VehicleBase::getTurnChoice(){return turnChoice;}


//setTurningState sets the turning boolean to true during the turn movement of a vehicle
//
//Parameter - bool state
//
void VehicleBase::setTurningState(int state){this->turningState = state;}


//getTurningState returns the turning state boolean
//
//Return - bool turningState
//
int VehicleBase::getTurningState(){return turningState;}


//setHead sets the head pointer for a vehicle
//
//Parameter - Section *head
//
void VehicleBase::setHead(Section* head){this->head = head;}


//setTail sets the tail pointer for a vehicle
//
//Parameter - Section *tail
//
void VehicleBase::setTail(Section* tail){this->tail = tail;}


//getHead returns a pointer to the front section of a vehicle
//
//Return - Section *head
Section* VehicleBase::getHead(){return this->head;}


//getTail returns a pointer to the back section of a vehicle
//
//Return - Section *tail
Section* VehicleBase::getTail(){return this->tail;}

#endif
