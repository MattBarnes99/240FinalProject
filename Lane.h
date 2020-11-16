#ifndef __LANE_H__
#define __LANE_H__

#include "Vehicle.h"
#include <vector>

using namespace std;

class Lane {
	public:
		vector<Vehicle> lane;

		Lane(int sections);
		Lane(const Lane& other);
		~Lane();
}

#endif