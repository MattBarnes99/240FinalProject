#ifndef __SECTION_H__
#define __SECTION_H__

#include <string>
#include "VehicleBase.fwd.h"

using namespace std;

class Section {
	
	protected:

		Section* next;
		Section* previous;
		bool occupied = false;
		VehicleBase* vehicleHere = nullptr;
		string name;

	public:
		
		Section();
		~Section();

		inline Section* getNext() {return next;};
		inline Section* getPrevious() {return previous;};
		inline string getName() {return name;};
		void setVehicle(VehicleBase* newVehicle);
		VehicleBase* getVehicle();
		void setOccupied(bool state);
		bool getOccupied();
		void setNext(Section *nextTile);
		void setPrevious(Section *prevTile);
		
};

#endif