#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"
#include <string>

using namespace std;

class Intersection {
	public:
		String direction;
		Intersection *north;
		Intersection *south;
		Intersection *east;
		Intersection *west;
		TrafficLight *NSLight;
		TrafficLight *EWLight;

		Intersection() {};
		~Intersection() {};

		inline void setDirection(String theDirection) {direction = theDirection;};
		inline void setNorth(Intersection *northIS) {north = northIS;};
		inline void setSouth(Intersection *southIS) {south = southIS;};
		inline void setEast(Intersection *eastIS) {east = eastIS;};
		inline void setWest(Intersection *westIS) {west = westIS;};
		inline void setNSTrafficLight(TrafficLight *NS) {NSLight = NS;};
		inline void setEWTrafficLight(TrafficLight *EW) {EWLight = EW;};
}