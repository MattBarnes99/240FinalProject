#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ConfigParser{
    private:
        map<string,string> parameters;
       
    public:
        ConfigParser();
        // Creates a map from file
        ConfigParser(string filename);
        // Returns map created from file
        map<string,string> get();

};