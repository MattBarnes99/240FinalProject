#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

using namespace std;

Lane::Lane(int sections) {
	lane.resize(sections);
}

Lane::Lane(const Lane& other) {
	lane = other.lane;
}

Lane::~Lane() {}

#endif