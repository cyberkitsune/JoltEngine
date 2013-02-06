/* 
 * File:   JoltDataFile.cpp
 * Author: cyberkitsune
 * 
 * Created on February 4, 2013, 9:20 PM
 */

#include "JoltDataFile.h"
#include <stdlib.h>

using namespace std;

JoltDataFile::JoltDataFile(const char* filename) {
    file.open(filename, std::ios::in);
}

string choppa(const string &t, const string &ws)
{
    string str = t;
    size_t found;
    found = str.find_last_not_of(ws);
    if (found != string::npos)
    	str.erase(found+1);
    else
    	str.clear();            

    return str;
}

int JoltDataFile::getInt(const char* prop) {
    //May not be the best way of doing this...
    //Example value... myValue = 5
    std::string str;
    while(std::getline(file,str)) {
        if(str.find_first_of("=") != std::string::npos) {
            string whiteSpace = choppa(str," ");
            return atoi(whiteSpace.substr(whiteSpace.find_first_of("=")).c_str());
        }
    }
    return -1; //We didn't find a value.
}

JoltDataFile::~JoltDataFile() {
    file.close();
}

