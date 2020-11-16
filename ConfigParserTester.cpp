#include <iostream>
#include <string>
#include "ConfigParser.h"

using namespace std;

int main(int argc, char* argv[]){
    cout << "Testing config parser: " << endl;
    cout << "-----------------------" << endl;

    cout << "Testing Constructor: " << endl;
    cout << "---------------------" << endl;

    ConfigParser config = ConfigParser(argv[1]);     


    cout << "Testing the get method: " << endl;
    cout << "------------------------" << endl;
    map<string,string> configParameters = config.get();

    cout << "Printing contents of new map: " << endl;
    cout << "------------------------------" << endl;

    for (auto it = configParameters.cbegin(); it != configParameters.cend(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}