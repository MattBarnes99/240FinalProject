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

		inline LightColor getColor() const {return this->color;}
		inline int getYellowTimeLeft() const {return this->yellowTimeLeft;}

		void decrement();
};

#endif