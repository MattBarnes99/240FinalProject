#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

using namespace std;

TrafficLight::TrafficLight(LightColor light_color, int green, int yellow, int red)
	: color{light_color},
	  greenLength{green},
	  greenTimeLeft{green},
	  yellowLength{yellow},
	  yellowTimeLeft{yellow},
	  redLength{red},
	  redTimeLeft{red}
	{}

TrafficLight::TrafficLight(const TrafficLight& other)
	: color{other.color},
	  greenLength{other.greenLength},
	  yellowLength{other.yellowLength}
	{}

TrafficLight::TrafficLight(){}

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

TrafficLight::~TrafficLight() {}

#endif