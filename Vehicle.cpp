#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__


#include "Vehicle.h"
#include <iostream>


//Constructor takes in Vehicle type, direction size, and rightTurn decision
//
//Parameters:
    // VehicleType, Direction, int size, bool rightTurn)
//
Vehicle::Vehicle(VehicleType type, Direction originalDirection, int size, bool rightTurn): VehicleBase(type,originalDirection), size{size}, turnChoice{rightTurn}{}


//Destructor
Vehicle::~Vehicle(){}


//getDir returns the current direction of the vehicle
//
Direction Vehicle::getDir(){return curDir;}


//setDir sets the current direction to the new direction
//
//Parameter - Direction newDir
//
void Vehicle::setDir(Direction newDir){curDir = newDir;}


//getSize returns the size of the vehicle
int Vehicle::getSize(){return size;}


//getTurnChoice returns the bool turnChoice of the vehicle
bool Vehicle::getTurnChoice(){return turnChoice;}


//setTurningState sets the turning boolean to true during the turn movement of a vehicle
//
//Parameter - bool state
//
void Vehicle::setTurningState(int state){this->turningState = state;}


//getTurningState returns the turning state boolean
//
//Return - bool turningState
//
int Vehicle::getTurningState(){return turningState;}


//setHead sets the head pointer for a vehicle
//
//Parameter - Section *head
//
void Vehicle::setHead(Section* head){this->head = head;}


//setTail sets the tail pointer for a vehicle
//
//Parameter - Section *tail
//
void Vehicle::setTail(Section* tail){this->tail = tail;}


//getHead returns a pointer to the front section of a vehicle
//
//Return - Section *head
Section* Vehicle::getHead(){return this->head;}


//getTail returns a pointer to the back section of a vehicle
//
//Return - Section *tail
Section* Vehicle::getTail(){return this->tail;}


#endif
