#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"

using namespace std;

Section::Section() {};

Section::~Section() {};

Section::setVehicle(VehicleBase *newVehicle) {
	vehicleHere = newVehicle;
}

Section::setOccupied() {
	if (vehicleHere == nullptr)
		occupied = true;
	else
		occupied = false;
}

Section::setNext(Section *nextTile) {
	next = nextTile;
}

Section::setPrevious(Section *prevTile) {
	previous = prevTile;
}