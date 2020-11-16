#include <iostream>
#include <string>
#include <random>

using namespace std;

class randomGen{
    private:
        mt19937 randomNumberGenerator;
    public:

        //Empty constructor
        randomGen();

        // Set the seed for random number generation
        void setSeed(int seed);

        // Get the random num
        double get();
};
