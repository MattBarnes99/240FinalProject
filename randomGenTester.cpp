#include <iostream>
#include <string>
#include <random>
#include "randomGen.h"

using namespace std;

int main(){
    cout << "Testing randomGen: " << endl;
    cout << "-------------------" << endl;

    cout << "Testing constructor: " << endl;
    cout << "---------------------" << endl;

    randomGen rand;

    cout << "Testing setSeed() method: " << endl;
    cout << "--------------------------" << endl;
    rand.setSeed(23456);

    cout << "Testing get() method: " << endl;
    cout << "----------------------" << endl;
    for (int x = 1; x < 100; x++){
        cout << "Get: " << x << " " << rand.get() << endl;
    }

    return 0;
}