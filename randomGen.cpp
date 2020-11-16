#include <iostream>
#include <random>
#include "randomGen.h"


// Empty constructor
randomGen::randomGen(){}

//setSeed sets the seed for random number generation
//
//Parameter - int seed
//
void randomGen::setSeed(int seed){randomNumberGenerator.seed(seed);}


//get returns a string of which car is generated
//
//return - string vehicle
double randomGen::get(){
    uniform_real_distribution<double> rand_double(0,1);
    return rand_double(randomNumberGenerator);
}

