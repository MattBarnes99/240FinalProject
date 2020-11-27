#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"
#include <iostream>

using namespace std;


//Constructor takes in the starting LightColor and the lenght of the different light states
// and assigns them to their relevant instance variables
//
TrafficLight::TrafficLight(LightColor light_color, int green, int yellow, int red)
	:color{light_color},
	greenLength{green},
	greenTimeLeft{green},
	yellowLength{yellow},
	yellowTimeLeft{yellow},
	redLength{red},
	redTimeLeft{red}
{
	
}


//Copy constructor
TrafficLight::TrafficLight(const TrafficLight& other)
	: color{other.color},
	  greenLength{other.greenLength},
	  greenTimeLeft{other.greenTimeLeft},
	  yellowLength{other.yellowLength},
	  yellowTimeLeft{other.yellowTimeLeft},
	  redLength{other.redLength},
	  redTimeLeft{other.redTimeLeft}
	{}


//Empty constructor
TrafficLight::TrafficLight(){}


//Destructor
TrafficLight::~TrafficLight() {}


//decrement will decrease the timeLeft variable for the given LightColor state
//and switch to the next LightColor if the timeLeft variable hits 0
//
void TrafficLight::decrement(){
	if (color == LightColor::green && greenTimeLeft > 0){
		greenTimeLeft--;
		if (greenTimeLeft == 0){
			color = LightColor::yellow;
			greenTimeLeft = greenLength;	
		}
	}else if (color == LightColor::yellow && yellowTimeLeft > 0){
		yellowTimeLeft--;
		if (yellowTimeLeft == 0){
			color = LightColor::red;
			yellowTimeLeft = yellowLength;	
		}
	}else if (color == LightColor::red && redTimeLeft > 0){
		redTimeLeft--;
		if (redTimeLeft == 0){
			color = LightColor::green;
			redTimeLeft = redLength;	
		}
	}

}


void TrafficLight::print(){
	if (color == LightColor::green){
		cout << "green: " << greenTimeLeft << endl;
	}else if (color == LightColor::yellow){
		cout << "yellow: " << yellowTimeLeft << endl;
	}else if (color == LightColor::red){
		cout << "red: " << redTimeLeft << endl;
	}
}

#endif