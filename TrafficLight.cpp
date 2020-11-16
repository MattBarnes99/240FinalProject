#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

using namespace std;

TrafficLight::TrafficLight(String light_color, int green, int yellow)
	: color{light_color},
	  greenLength{green},
	  yellowLength{yellow}
	{}

TrafficLight::TrafficLight(const TrafficLight& other)
	: color{other.color},
	  greenLength{other.greenLength},
	  yellowLength{other.yellowLength}
	{}

TrafficLight::~TrafficLight() {}

#endif