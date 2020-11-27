#include <algorithm>
#include "ConfigParser.h"

using namespace std;


//Method to remove whitespace from input file
string preprocess(string line){
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); // removes whitespaces
    return line;
}


//Empty Constructor
ConfigParser::ConfigParser(){}


// Constructor takes in input file and converts it to a map
//
//Parameter - string input file
//
ConfigParser::ConfigParser(string filename){
    ifstream in;
    in.open(filename.c_str());

    if(in.bad()){
        std::cout << "Incorrect Input File" << std::endl;
    }
    else{
        string line;
        while(getline(in, line)){
            line = preprocess(line);
            if(line.empty())
                continue;
            size_t index = line.find(":");
            parameters[line.substr(0, index)] = line.substr(index + 1, line.length());
        }
    }
}


//get returns the map of input parameters
//
//return - map<string, string>
string ConfigParser::get(string in){return parameters[in];}