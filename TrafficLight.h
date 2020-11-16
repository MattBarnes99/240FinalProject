#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

using namespace std;

class TrafficLight {
	public:
		String color;
		int greenLength;
		int yellowLength;

		TrafficLight(String light_color, int green, int yellow);
		TrafficLight(const TrafficLight& other);
		~TrafficLight();

		inline String getColor() const {return this->color;}
		inline int getGreenLength() const {return this->greenLength;}
		inline int getYellowLength() const {return this->yellowLength;}

		inline void setColor(String light_color) {color = light_color;}
		inline void setGreenLength(int green) {greenLength = green;}
		inline void setYellowLength(int yellow) {yellowLength = yellow;}
};

#endif