#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"

using namespace std;

//Empty Consructor
Section::Section(): name{"section"} {};


//Destructor
Section::~Section(){};


//setVehicle sets the Vehicle* instance variable of a section to the input
//
//Parameter - VehicleBase* newVehicle
//
void Section::setVehicle(VehicleBase* newVehicle){vehicleHere = newVehicle;}


//setOccupied sets the occupied instance varaible to the given bool
//
//Parameter - bool state
//
void Section::setOccupied(bool state){occupied = state;}


//setNext sets the Section* next instance variable to the given Section*
//
//Parameter - Section* nextTile
//
void Section::setNext(Section* nextTile){next = nextTile;}


//setPrevious sets the Section* previous instance variable to the given Section*
//
//Parameter - Section* prevTile
//
void Section::setPrevious(Section* prevTile){previous = prevTile;}


//getOccupied returns the occupied instance variable
//
//return - bool occupied
//
bool Section::getOccupied(){return occupied;}


//getVehicle returns a VehicleBase pointer of the given section
//
//return - VehicleBase* here
VehicleBase* Section::getVehicle(){return vehicleHere;}

#endif