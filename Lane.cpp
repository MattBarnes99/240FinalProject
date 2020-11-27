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
Lane::Lane(int halfsize, Direction dir, Intersection* intOne, Intersection* intTwo){

	//Intialize instance variables
	this->intOne = intOne;
	this->intTwo = intTwo;
	this->dir = dir;
	this->halfsize = halfsize;
	this->size = (halfsize*2) + 8 + 2;

	//adds four offbounds section pointers to lane
	for (int i = 0; i < 4; i++){
		lane.push_back(new Section());
	}

	//adds sections before intersection
	for (int i = 0; i < halfsize; i++){
		lane.push_back(new Section());
	}

	//adds first intersection
	lane.push_back(intOne);

	//adds second intersection
	lane.push_back(intTwo);

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
Lane::~Lane(){
	for (int i = 0; i < this->size; i++){
		if (lane[i]->getName() == "section"){
			delete this->lane[i];
		}
	}
	lane.clear();
}


//placeVehicle method places the vehicle at the starting section of the lane
//  will backfill the rest of the sections on the offbounds sections
//
//Parameter - VehicleBase* veh
//
void Lane::placeVehicle(VehicleBase* veh){

  //set the head of the vehicle to the start section
  veh->setHead(start);

  //set that sections occupied boolean to true and assign the vehicle to the section
  start->setOccupied(true);
  start->setVehicle(veh);

  //set the previous section to true and assign the vehicle to that section
  start->getPrevious()->setOccupied(true);
  start->getPrevious()->setVehicle(veh);

  //If vehicle is car, set the tail to the second section
  if (veh->getVehicleType() == VehicleType::car){
    veh->setTail(start->getPrevious());
  //If vehicle is suv, assign another section and set tail to third section
  }else if(veh->getVehicleType() == VehicleType::suv){
    start->getPrevious()->getPrevious()->setOccupied(true);
    start->getPrevious()->getPrevious()->setVehicle(veh);
    veh->setTail(start->getPrevious()->getPrevious());
  //If vehicle is truck, assign two more sections and set tail to fourth section
  }else{
    start->getPrevious()->getPrevious()->setOccupied(true);
    start->getPrevious()->getPrevious()->setVehicle(veh);
    start->getPrevious()->getPrevious()->getPrevious()->setOccupied(true);
    start->getPrevious()->getPrevious()->getPrevious()->setVehicle(veh);
    veh->setTail(start->getPrevious()->getPrevious()->getPrevious());
  }
}


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
		//check there is a vehcile in the section
		if (lane[i]->getVehicle() != nullptr){
			//Check the vehicle at that section is the head of the vehicle
			//Check the vehicle's AlreadyMoved boolean is false
			if (lane[i]->getVehicle()->getHead() == lane[i] && lane[i]->getVehicle()->getAlreadyMoved() == false){
				move(lane[i], i, color, yellowTimeLeft);
			}
		}else{
			continue;
		}
	}
}

// move contains all of the logic to decide how a vehicle should move 
// after being called by the advance method
//
//Parameters:
//		Section* sec - section containing head of vehicle
//		int index - index of section in lane
//		LightColor color - current TrafficLight LightColor
// 		int yellowTimeLeft - time left on yellow if LightColor == yellow
//
void Lane::move(Section* sec, int index, LightColor color, int yellowTimeLeft){

	//Check for in or after intersection and going straight	
	if (index >= size/2 && lane[index+1]->getOccupied() == false && sec->getVehicle()->getTurnChoice() == false){
		moveForward(sec,index);
		removeVehicle(lane[index+1]);
	}

	//Before the intersection
	else if (index < size/2-1 && lane[index+1]->getOccupied() == false){
		moveForward(sec,index);
	}

	//Vehicle is about to enter intersection
	else if (index == (size/2-1) && sec->getNext()->getOccupied() == false){
		//moveForward if the turn choice is false and the vehicle has a green light
		if (color == LightColor::green && sec->getVehicle()->getTurnChoice() == false){
			moveForward(sec,index);
		//turn Right if the vehicle has a green light and the turnChoice is true
		}else if (color == LightColor::green && sec->getVehicle()->getTurnChoice() == true){
			turn(sec);
		//Condition of yellow light and going straight
		}else if (color == LightColor::yellow && sec->getVehicle()->getTurnChoice() == false){
			//Check if car has enough time to make it through the intersection before red
			if (sec->getVehicle()->getSize() == 2 && yellowTimeLeft >= 4){
				moveForward(sec,index);
			}
			//Check if suv has enough time to make it through the intersection before red
			else if (sec->getVehicle()->getSize() == 3 && yellowTimeLeft >= 5){
				moveForward(sec,index);
			}
			//Check if truck has enough time to make it through the intersection before red
			else if (sec->getVehicle()->getSize() == 4 && yellowTimeLeft >= 6){
				moveForward(sec,index);
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

	//Vehicle is in first place of intersection and turning
	else if (index == size/2 && sec->getVehicle()->getTurnChoice()){
		turn(sec);
	}
}


// moveForward will move vehicles forward that are immediately before or 
// in the intersection
//
// Parameter - Section* sec is the section that the vehicle is moving from
//
void Lane::moveForward(Section* sec,int index){
	//Set alreadyMoved bool to true for vehicle
	sec->getVehicle()->setAlreadyMoved(true);
	//update head of vehicle to next section
	sec->getVehicle()->setHead(lane[index+1]);
	lane[index+1]->setVehicle(sec->getVehicle());
	lane[index+1]->setOccupied(true);
	//update tail to next section
	sec->getVehicle()->getTail()->setOccupied(false);
	sec->getVehicle()->getTail()->setVehicle(nullptr);
	sec->getVehicle()->setTail(lane[1+index-(sec->getVehicle()->getSize())]);
}


// turn controls the turn movements of a given vehicle
//
// Parameter - Section* sec is the section that the vehicle is turning from
//
void Lane::turn(Section* sec){
	//Set alreadyMoved bool to true for vehicle
	sec->getVehicle()->setAlreadyMoved(true);


	//if(head is at the int)
		//head moves up
		//tail is now tail-> getNext
		//
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
	for (unsigned int i = 4; i<(lane.size()-4); i++){
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
	//for loop creates the links for next and previous for the tiles
	//does not include the n,s,e,w pointers for the intersection
	for (unsigned int i = 0; i < lane.size()-1; i++){
		if (lane[i] == lane[size/2-1]){
			lane[i]->setNext(lane[i+1]);
		}else if (lane[i] == lane[size/2]){
			continue;
		}else if (lane[i] == lane[size/2+1]){
			lane[i+1]->setPrevious(lane[i]);
		}else{
			lane[i]->setNext(lane[i+1]);
			lane[i+1]->setPrevious(lane[i]);
		}
		
	}

	//Creation of n,s,e,w pointers for the intersections depending on direction
	if (dir == Direction::north){
		intOne->setSouth(lane[size/2-1]);
		intOne->setNorth(intTwo);
		intTwo->setSouth(intOne);
		intTwo->setNorth(lane[size/2+2]);
	}else if (dir == Direction::south){
		intOne->setNorth(lane[size/2-1]);
		intOne->setSouth(intTwo);
		intTwo->setNorth(intOne);
		intTwo->setSouth(lane[size/2+2]);
	}else if (dir == Direction::east){
		intOne->setEast(intTwo);
		intOne->setWest(lane[size/2-1]);
		intTwo->setEast(lane[size/2+2]);
		intTwo->setWest(intOne);
	}else if (dir == Direction::west){
		intOne->setWest(intTwo);
		intOne->setEast(lane[size/2-1]);
		intTwo->setWest(lane[size/2+2]);
		intTwo->setEast(intOne);
	}
}


//resetMoveBool resets all the alreadyMoved booleans for the vehicles in the lane.
//to be called on all the lanes after all lanes have advanced.
//
void Lane::resetMoveBool(){
	for (int i = 0; i < size; i++){
		lane[i]->getVehicle()->setAlreadyMoved(false);
	}
}

#endif
