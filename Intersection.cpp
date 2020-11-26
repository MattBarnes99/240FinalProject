#ifndef __INTERSECTION_CPP__
#define __INTERSECTION_CPP__

#include "Intersection.h"

using namespace std;

//Empty constructor
Intersection::Intersection(): Section() {};


//Destructor
Intersection::~Intersection(){};


//setRight sets the right instance variable for the intersection
// needed for the right turn operations
//
void Intersection::setRight(Section *right){this->right = right;}

#endif