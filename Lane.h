#ifndef __LANE_H__
#define __LANE_H__

#include "Section.h"
#include "Intersection.h"
#include "VehicleBase.h"
#include "TrafficLight.h"
#include <vector>

using namespace std;

class Lane {

	private:
		Section* start;
		Section* end;
		Intersection* intOne;
		Intersection* intTwo;
		Direction dir; 
		int size; //total size of lane
		int halfsize; //number of sections befor intersection
		vector<Section*> lane;

		void link(); // will create the next and previous links for the sections
		void move(Section* sec, int index, LightColor color, int yellowTimeLeft);
		void turn(Section* sec);
		void moveAfterInt(Section* sec);
		void moveBeforeInt(Section* sec);
		void removeVehicle(Section* sec);
		void moveForward(Section* sec);

	public:

		Lane(int sections, Direction dir, Intersection* interSectionOne, Intersection* interSectionTwo);
		Lane(const Lane& other);
		Lane();
		~Lane();

		Section* getEnd(); //returns the last inbounds section of the lane
		Section* getStart(); //returns the first inbounds section of the lane

		vector<VehicleBase*> getVehicleVector(); //vector to be passed to the animator

		void advance(LightColor color, int yellowTimeLeft); //control for advancement of the vehicles in the lane
		void resetMoveBool(); //resets the already moved boolean for all vehicles in a lane - to be called after all advancement is done on all lanes

		bool openSpace(); //check if space is open for vehicle generation

		void placeVehicle(VehicleBase* veh);

};

#endif
