#ifndef __CLOCK_CPP__
#define __CLOCK_CPP__

#include "Clock.h"

using namespace std;

Clock::Clock(int time):counter{time}{}

Clock::~Clock(){}

void Clock::increment(){
	if(cin.get() == '\n'){
		counter++;
	}
}

#endif
























