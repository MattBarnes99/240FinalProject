#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>
#include "VehicleBase.h"

using namespace std;

class TrafficLight {
	
	private:
	
		LightColor color;
		int greenLength;
		int greenTimeLeft;
		int yellowLength;
		int yellowTimeLeft;
		int redLength;
		int redTimeLeft;

	public:
		
		TrafficLight(LightColor light_color, int green, int yellow, int red);
		TrafficLight(const TrafficLight& other);
		
		TrafficLight();
		~TrafficLight();

		//retuns the color of the light
		inline LightColor getColor() const {return this->color;}

		//returns the int value left for the yellow light
		inline int getYellowTimeLeft() const {return this->yellowTimeLeft;}

		//will decrement the time left variable for the current LightColor state
		void decrement();
};

#endif