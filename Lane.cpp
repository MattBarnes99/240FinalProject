#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

using namespace std;


//Constructor takes creates the lane based on the halfsize, and two intersection sections
// four offbounds sections will be created for vehicle intialization and for when the vehicle exits
// the road
//
//Parameters:
//		int halfsize - number of sections before intersection
//		Intersection* one - first intersection section
//		Intersection* two - second intersection section
//
Lane::Lane(int halfsize, Intersection* interSectionOne, Intersection* interSectionTwo) {
	
	//adds four offbounds section pointers to lane
	for (int i = 0; i < 4; i++){
		lane.push_back(new Section());
	}

	//adds sections before intersection
	for (int i = 0; i < halfsize; i++){
		lane.push_back(new Section());
	}

	//adds first intersection
	lane.push_back(interSectionOne);

	//adds second intersection
	lane.push_back(interSectionTwo);

	//adds sections after intersection
	for (int i = 0; i < halfsize; i++){
		lane.push_back(new Section());
	}

	//adds last four offbounds sectionpointers
	for (int i = 0; i < 4; i++){
		lane.push_back(new Section());
	}

	//set the start and end pointers for the inbound sections
	this->start = lane[4];
	this->end = lane[lane.size()-4];

	//call the private link method to set the next and previous sections for each tile
	link();

}


//Copy constructor
Lane::Lane(const Lane& other) {
	lane = other.lane;
}


//Empty Constructor
Lane::Lane(){}


//Destructor
Lane::~Lane(){}


//getVehicleVector returns a vector of vehicleBase* to be sent to the animator
// does not include the offbound sections
//
//return - vector<VehicleBase*>
//
vector<VehicleBase*> Lane::getVehicleVector(){
	vector<VehicleBase*> ret;
	for (int i = 4; i<(lane.size()-4); i++){
		if (lane[i]->getOccupied()){
			ret.push_back(lane[i]->getVehicle());
		}else{
			ret.push_back(nullptr);
		}
	}
	return ret;
}


//getStart returns a pointer to the start of the inbounds sections
//
//return - Section* start
Section* Lane::getStart(){return start;}


//getEnd returns a pointer to the end of the inbounds sections
//
//return - Section* end
Section* Lane::getEnd(){return end;}


//advance is the intitiating structure to move the vehicles in a given lane
// creates an iterator from end to beginning of 



//link creates the next and previous links for each section in a lane
//
void Lane::link(){
	for (int i = 0; i < lane.size()-1; i++){
		lane[i]->setNext(lane[i+1]);
		lane[i+1]->setPrevious(lane[i]);
	}
}

#endif