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

        ConfigParser(string filename);  // Creates a map from file

        map<string,string> get();       // Returns map created from file

};