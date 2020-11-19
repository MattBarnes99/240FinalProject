#ifndef __SECTION_H__
#define __SECTION_H__

#include <string>

using namespace std;

class Section {
	public:
		Section *next;
		Section *previous;
		Bool occupied;
		VehicleBase *vehicleHere;
		String name;

		Section() {};
		~Section() {};

		inline Section* getNext() {return next;};
		inline Section* getPrevious() {return previous;};
		inline String getName() {return name;};
		void setVehicle(VehicleBase* newVehicle);
		void setOccupied();
		void setNext(Section *nextTile);
		void setPrevious(Section *prevTile);
}