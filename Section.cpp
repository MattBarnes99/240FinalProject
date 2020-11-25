#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"

using namespace std;

Section::Section() {};

Section::~Section() {};

void Section::setVehicle(VehicleBase* newVehicle) {
	vehicleHere = newVehicle;
}

void Section::setOccupied(bool state) {
	occupied = state;
}

void Section::setNext(Section *nextTile) {
	next = nextTile;
}

void Section::setPrevious(Section *prevTile) {
	previous = prevTile;
}

bool Section::getOccupied(){
	return occupied;
}

VehicleBase* Section::getVehicle(){
	return vehicleHere;
}

#endif
