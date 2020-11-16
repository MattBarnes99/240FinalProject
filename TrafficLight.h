#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>

using namespace std;

class TrafficLight {
	public:
		string color;
		int greenLength;
		int yellowLength;

		TrafficLight(string light_color, int green, int yellow);
		TrafficLight(const TrafficLight& other);
		~TrafficLight();

		inline string getColor() const {return this->color;}
		inline int getGreenLength() const {return this->greenLength;}
		inline int getYellowLength() const {return this->yellowLength;}

		inline void setColor(string light_color) {color = light_color;}
		inline void setGreenLength(int green) {greenLength = green;}
		inline void setYellowLength(int yellow) {yellowLength = yellow;}
};

#endif