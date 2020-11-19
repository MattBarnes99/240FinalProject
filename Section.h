#ifndef __SECTION_H__
#define __SECTION_H__

#include "VehicleBase.h"
#include <string>

using namespace std;

class Section {
	public:
		Section* next;
		Section* previous;
		bool occupied;
		VehicleBase* vehicleHere;
		string name;

		Section() {};
		~Section() {};

		inline Section* getNext() {return next;};
		inline Section* getPrevious() {return previous;};
		inline string getName() {return name;};
		void setVehicle(VehicleBase* newVehicle);
		void setOccupied();
		void setNext(Section* nextTile);
		void setPrevious(Section* prevTile);
};

#endif