#ifndef __LANE_H__
#define __LANE_H__

#include "Section.h"
#include "Intersection.h"
#include <vector>

using namespace std;

class Lane {
	
	private:
		Section* start;
		Section* end;
		vector<Section *> lane;
		int size; //size of the lane not counting offbounds sections
		void link(); // will create the next and previous links for the sections
	
	public:
		
		Lane(int sections, Intersection* interSectionOne, Intersection* interSectionTwo);
		Lane(const Lane& other);
		Lane();
		Section* getEnd(); // returns the last inbounds section of the lane
		Section* getStart(); //returns the first inbounds section of the lane
		~Lane();
		vector<VehicleBase*> getVehicleVector();

};

#endif