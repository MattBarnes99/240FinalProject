#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

using namespace std;


// Constructor takes creates the lane based on the halfsize, and two intersection sections
// four offbounds sections will be created for vehicle intialization and for when the vehicle exits
// the road
//
// Parameters:
//		int halfsize - number of sections before intersection
//		Intersection* one - first intersection section
//		Intersection* two - second intersection section
//
Lane::Lane(int halfsize, Intersection* interSectionOne, Intersection* interSectionTwo): halfsize{halfsize} {

	//set the total size of the lane
	size = (halfsize*2) + 8 + 2;

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


// advance is the intitiating structure to move the vehicles in a given lane
// creates an iterator starting at the end of the lane and iterates down
// calling appropriate move methods as needed
//
// Parameter - LightColor color is the color of the light for this lane at 
// this moment
// Parameter - int yellowTimeLeft is how much time is left for the yellow 
// light for this lane
//
void Lane::advance(LightColor color, int yellowTimeLeft){
	for (int i = lane.size()-1; i > -1; i--){
		if (lane[i]->getVehicle() != nullptr){
			if (lane[i]->getVehicle()->getHead() == lane[i]){
				move(lane[i],i,color,yellowTimeLeft);
			}
		}else{
			continue;
		}
	}
}

// move contains all of the logic to decide how a vehicle should move 
// after being called by the advance method
//
// Parameter - Section* sec is the lane section to move the vehicle from
// Parameter - int index is the index of the given section in the lane
// Parameter - LightColor color is the color of the light for this lane at 
// this moment
// Parameter - int yellowTimeLeft is how much time is left for the yellow 
// light for this lane
//
void Lane::move(Section* sec, int index, LightColor color, int yellowTimeLeft){

	//Check to see if vehicle is after the intersection
	if (index >= (size/2+2)){
		moveAfterInt(sec);
	}

	//Check to see if the vehicle is in the second space of the intersection
	else if (index == size/2){
		
	}

	//Check to see if vehicle is in the first space of the intersection
	else if (index == size/2){
		//call turn method if the turnChoice of the vehicle is true
		if (sec->getVehicle()->getTurnChoice()){
			turn(sec);
		//call the moveForward method if the turn choice is false
		}else{
			moveForward(sec);
		}
	}

	//Check to see if vehicle is immediately before the intersection
	else if (index == (size/2-1)){
		//moveForward if the turn choice is false and the vehicle has a green light
		if (color == LightColor::green && sec->getVehicle()->getTurnChoice() == false){
			moveForward(sec);
		//turn Right if the vehicle has a green light and the turnChoice is true
		}else if (color == LightColor::green && sec->getVehicle()->getTurnChoice() == true){
			turn(sec);
		//Condition of yellow light and going straight
		}else if (color == LightColor::yellow && sec->getVehicle()->getTurnChoice() == false){
			//Check if car has enough time to make it through the intersection before red
			if (sec->getVehicle()->getSize() == 2 && yellowTimeLeft >= 4){
				moveForward(sec);
			}
			//Check if suv has enough time to make it through the intersection before red
			else if (sec->getVehicle()->getSize() == 3 && yellowTimeLeft >= 5){
				moveForward(sec);
			}
			//Check if truck has enough time to make it through the intersection before red
			else if (sec->getVehicle()->getSize() == 4 && yellowTimeLeft >= 6){
				moveForward(sec);
			}
		}
		//Condition of yellow light and turning right
		else if (color == LightColor::yellow && sec->getVehicle()->getTurnChoice() == true){
			if (sec->getVehicle()->getSize() == 2 && yellowTimeLeft >= 3){
				turn(sec);
			}
			//Check if suv has enough time to make it through the intersection before red
			else if (sec->getVehicle()->getSize() == 3 && yellowTimeLeft >= 4){
				turn(sec);
			}
			//Check if truck has enough time to make it through the intersection before red
			else if (sec->getVehicle()->getSize() == 4 && yellowTimeLeft >= 5){
				turn(sec);
			}
		}
	}
	
	//Else, vehicle is before intersection
	else{
		moveBeforeInt(sec);
	}
}


// turn controls the turn movements of a given vehicle
//
// Parameter - Section* sec is the section that the vehicle is turning from
//
void Lane::turn(Section* sec){
	//if(head is at the int)
		//head moves up
		//tail is now tail-> getNext
		//
}



// moveAfterInt will move vehicles forward if they are in the second place of
// the intersection or after, and will remove vehicles if they are offbounds
//
// Parameter - Section* sec is the section that the vehicle is moving from
//
void Lane::moveAfterInt(Section* sec){

	VehicleBase* veh = sec->getVehicle();
	//update head of vehicle to next section
	veh->setHead(sec->getNext());
	sec->getNext()->setVehicle(veh);
	sec->getNext()->setOccupied(true);
	//update tail to next section
	veh->getTail()->setOccupied(false);
	veh->getTail()->setVehicle(nullptr);
	veh->setTail(veh->getTail()->getNext());

	//check to see if vehicle is offbounds and should be deleted
	removeVehicle(sec->getNext()); 
}


// moveBeforeInt will move vehicles forward that are before the intersection
//
// Parameter - Section* sec is the section that the vehicle is moving from
//
void Lane::moveBeforeInt(Section* sec){
	if (sec->getNext()->getOccupied() == false){
		VehicleBase* veh = sec->getVehicle();
		//update head of vehicle to next section
		veh->setHead(sec->getNext());
		sec->getNext()->setVehicle(veh);
		sec->getNext()->setOccupied(true);
		//update tail to next section
		veh->getTail()->setOccupied(false);
		veh->getTail()->setVehicle(nullptr);
		veh->setTail(veh->getTail()->getNext());
	}
}

// moveForward will move vehicles forward that are immediately before or 
// in the intersection
//
// Parameter - Section* sec is the section that the vehicle is moving from
//
void Lane::moveForward(Section* sec) {
	moveBeforeInt(sec);
}

// removeVehicle will delete a vehicle once it has completely left the inbounds
// section of the lane
//
// Parameter - Section* sec is the section that the vehicle will be removed from
//
void Lane::removeVehicle(Section* sec){
	if (sec->getVehicle()->getTail() == lane[halfsize*2+7]){
		if (sec->getVehicle()->getSize() == 2){
			sec->setOccupied(false);
			sec->setVehicle(nullptr);
			sec->getPrevious()->setOccupied(false);
			sec->getPrevious()->setVehicle(nullptr);
		}else if(sec->getVehicle()->getSize() == 3){
			sec->setOccupied(false);
			sec->setVehicle(nullptr);
			sec->getPrevious()->setOccupied(false);
			sec->getPrevious()->setVehicle(nullptr);
			sec->getPrevious()->getPrevious()->setOccupied(false);
			sec->getPrevious()->getPrevious()->setVehicle(nullptr);
		}else{
			sec->setOccupied(false);
			sec->setVehicle(nullptr);
			sec->getPrevious()->setOccupied(false);
			sec->getPrevious()->setVehicle(nullptr);
			sec->getPrevious()->getPrevious()->setOccupied(false);
			sec->getPrevious()->getPrevious()->setVehicle(nullptr);
			sec->getPrevious()->getPrevious()->getPrevious()->setOccupied(false);
			sec->getPrevious()->getPrevious()->getPrevious()->setVehicle(nullptr);
		}
	}
}


// getVehicleVector returns a vector of vehicleBase* to be sent to the animator
// does not include the offbound sections
//
// Return - vector<VehicleBase*> 
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


// openSpace returns true if the starting section is not occupied
//
// Return - bool isOpen
//
bool Lane::openSpace(){
	bool ret = true;
	if (start->getOccupied() == true){ret = false;}
	return ret;
}


// getStart returns a pointer to the start of the inbounds sections
//
// Return - Section* start
//
Section* Lane::getStart(){return start;}


// getEnd returns a pointer to the end of the inbounds sections
//
// Return - Section* end
//
Section* Lane::getEnd(){return end;}


// link creates the next and previous links for each section in a lane
//
void Lane::link(){
	for (int i = 0; i < lane.size()-1; i++){
		lane[i]->setNext(lane[i+1]);
		lane[i+1]->setPrevious(lane[i]);
	}
}

#endif
