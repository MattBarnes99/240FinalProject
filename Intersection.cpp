#ifndef __INTERSECTION_CPP__
#define __INTERSECTION_CPP__

#include "Intersection.h"

using namespace std;

Intersection::Intersection(): Section() {};

Intersection::~Intersection(){};

void Intersection::setRight(Section *right){this->right = right;}

#endif