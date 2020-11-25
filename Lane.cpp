#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"
#include <iostream>

using namespace std;

Lane::Lane(int halfsize, Intersection* interSectionOne, Intersection* interSectionTwo) {
	
	//adds four offbounds section pointers to lane
	for (int i = 0; i < 4; i++){
		lane.push_back(new Section());
	}
	cout << "hidden size: " << lane.size() << endl;

	//adds sections before intersection
	for (int i = 0; i < halfsize; i++){
		lane.push_back(new Section());
	}
	cout << ": " << lane.size() << endl;

	//adds first intersection
	lane.push_back(interSectionOne);

	//adds second intersection
	lane.push_back(interSectionTwo);
	cout << "hidden/start/middle/int size: " << lane.size() << endl;

	//adds sections after intersection
	for (int i = 0; i < halfsize; i++){
		lane.push_back(new Section());
	}
	cout << "hidden/start/middle/int/aft size: " << lane.size() << endl;

	//adds last four offbounds sectionpointers
	for (int i = 0; i < 4; i++){
		lane.push_back(new Section());
	}
	cout << "finished size: " << lane.size() << endl;

	//set the start and end pointers for the inbound sections
	this->start = lane[4];
	this->end = lane[lane.size()-4];

	//call the private link method to set the next and previous sections for each tile
	link();

}

Lane::Lane(const Lane& other) {
	lane = other.lane;
}

Lane::Lane(){}

Lane::~Lane(){}

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

Section* Lane::getStart(){return start;}

Section* Lane::getEnd(){return end;}

void Lane::link(){
	for (int i = 0; i < lane.size()-1; i++){
		lane[i]->setNext(lane[i+1]);
		lane[i+1]->setPrevious(lane[i]);
	}
}


#endif