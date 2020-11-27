#ifndef __INTERSECTION_CPP__
#define __INTERSECTION_CPP__

#include "Intersection.h"

using namespace std;

//Empty constructor
Intersection::Intersection(): Section(){
    name = "intersection";
};


//Destructor
Intersection::~Intersection(){};


//setters for section pointers
void Intersection::setNorth(Section *sec){north = sec;}
void Intersection::setSouth(Section *sec){south = sec;}
void Intersection::setEast(Section *sec){east = sec;}
void Intersection::setWest(Section *sec){west = sec;}


//getters for section pointers
Section* Intersection::getNorth(){return north;}
Section* Intersection::getSouth(){return south;}
Section* Intersection::getEast(){return east;}
Section* Intersection::getWest(){return west;}



#endif