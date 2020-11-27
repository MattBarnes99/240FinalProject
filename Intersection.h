#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"
#include "VehicleBase.h"

using namespace std;

class Intersection : public Section{
	
	private:
		
		Section* north;
		Section* south;
		Section* east;
		Section* west;
	
	public:
		
		Intersection();
		~Intersection();
		
		//setters for section pointers
		void setNorth(Section *sec);
		void setSouth(Section *sec);
		void setEast(Section *sec);
		void setWest(Section *sec);

		//getters for section pointers
		Section* getNorth();
		Section* getSouth();
		Section* getEast();
		Section* getWest();

		
};

#endif