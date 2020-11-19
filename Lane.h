#ifndef __LANE_H__
#define __LANE_H__

#include "Section.h"
#include <vector>

using namespace std;

class Lane {
	public:
		vector<Section> lane;

		Lane(int sections);
		Lane(const Lane& other);
		Lane();
		~Lane();
};

#endif