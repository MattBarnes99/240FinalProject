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


//moveCheck checks to see if a given vehicle can move to the next tile
// will call moveForward if it can, otherwise nothing
//
//void Vehicle::moveCheck(){
  //check light - if green,
  //check vehicles head
  // see if the next section after head is occupied
  // if not occupied - move

  // if yellow, check if can exit intersection before turn red
  // if not, don't move,
  // if yes, check section after head section if it is occupied
  // if it is not occupied, move

  //^ will need two different checks for the yellow light because a vehicle
  // getting through the intersection before red depends on if it is going straight or turning
  // for example, a car takes 4 ticks to get through going straight and 3 when turning.

  //check if light is red
  // if it is, don't move

}


//moveForward will take in a vehicle pointer and move the vehicle forward one space
//
//Parameter - Vehicle *veh
//
void Vehicle::moveForward(Vehicle *veh){ //sum bout a setVehicle that needs to be included?
  if(this->getVehicleType() == VehicleType::car && this->head.next.setOccupied() == false){
    this->head = head.next;
    head.setOccupied();
    this->tail.setOccupied = false;
    this->tail = tail.next;
    tail.setOccupied();
  }
  else if(this->getVehicleType() == VehicleType::suv && this->head.next.setOccupied() == false){
    this->head = head.next;
    head.setOccupied();
    head->previous->setOccupied();
    this->tail.setOccupied = false;
    this->tail = tail.next;
    tail.setOccupied();
  }
  else if(this->getVehicleType() == VehicleType::truck && this->head.next.setOccupied() == false){
    this->head = head.next;
    head.setOccupied();
    head->previous->setOccupied();
    head->previous->previous->setOccupied();
    this->tail.setOccupied = false;
    this->tail = tail.next;
    tail.setOccupied();
  }
}


/*head.next.setOccupied = true;
head = head.next;
head.setVehicle = this;
tail.setOccupied = false;
tail = tail.next;
tail.setVehicle(this);*/
//turnCheck checks to see if a given vehicle can turn right
// will call turnRight() if it can, otherwise nothing
//void Vehicle::turnCheck(){}


//turnRight will take in a vehicle pointer and start the right turn
//
//Parameter - Vehicle *veh
//void Vehicle::turnRight(Vehicle *veh){}


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


//getGreenLight returns a boolean value of true if the TrafficLight is green
//
bool Vehicle::getGreenLight(){return greenLight;}


//getYellowLight returns a boolean value of true if the TrafficLight is yellow
bool Vehicle::getYellowLight(){return yellowLight;}


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


//removeVehicle is used to dynamically delete a vehicle object once it fully leaves the visible road section
//
//Parameter - Vehicle *done
//
void Vehicle::removeVehicle(Vehicle *done){}


//placeVehicle method places the vehicle at the starting section of a given lane
//  will backfill the rest of the sections on the invisible sections
//
//Parameter - Section *start
//
void Vehicle::placeVehicle(Section *start){

  //set the head of the vehicle to the given section
  this->head = start;

  //set that sections occupied boolean to true and assign the vehicle to the section
  start->setOccupied(true);
  start->setVehicle(this);

  //set the previous section to true and assign the vehicle to that section
  start->getPrevious()->setOccupied(true);
  start->getPrevious()->setVehicle(this);

  //If vehicle is car, set the tail to the second section
  if (this->getVehicleType() == VehicleType::car){
    this->setTail(start->getPrevious());
  //If vehicle is suv, assign another section and set tail to third section
  }else if(this->getVehicleType() == VehicleType::suv){
    start->getPrevious()->getPrevious()->setOccupied(true);
    start->getPrevious()->getPrevious()->setVehicle(this);
    this->setTail(start->getPrevious()->getPrevious());
  //If vehicle is truck, assign two more sections and set tail to fourth section
  }else{
    start->getPrevious()->getPrevious()->setOccupied(true);
    start->getPrevious()->getPrevious()->setVehicle(this);
    start->getPrevious()->getPrevious()->getPrevious()->setOccupied(true);
    start->getPrevious()->getPrevious()->getPrevious()->setVehicle(this);
    this->setTail(start->getPrevious()->getPrevious()->getPrevious());
  }
}


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
