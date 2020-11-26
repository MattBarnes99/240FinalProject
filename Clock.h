#ifndef __CLOCK_H__
#define __CLOCK_H__

using namespace std;

class Clock{

	private:

		int counter;

	public:

		Clock(int time);
		~Clock();
		void decrement(); //decrements the clock by one
		
};

#endif
























