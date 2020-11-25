#ifndef __CLOCK_CPP__
#define __CLOCK_CPP__

#include "Clock.h"

using namespace std;


//Constructor sets the max time instance variable
//
Clock::Clock(int time):counter{time}{}


//Destructor
Clock::~Clock(){}


//decrement decreases the clock by one
void Clock::decrement(){counter--;}

#endif
























