/* 
 * File:   JoltDataFile.cpp
 * Author: cyberkitsune
 * 
 * Created on February 4, 2013, 9:20 PM
 */

#include "JoltDataFile.h"
#include "JoltConsole.h"
#include <algorithm>
#include <stdlib.h>

using namespace std;

JoltDataFile::JoltDataFile(const char* filename) {
    file.open(filename, std::ios::in);
    
    if(file.fail()) {
        JoltConsole::logInfo("File","Failed file %s!", filename);
    }
    
    if(file.bad()) {
        JoltConsole::logInfo("File","Bad file %s!", filename);
    }
}

string delSpaces(string &str) 
{
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}

int JoltDataFile::getInt(const char* prop) {
    //May not be the best way of doing this...
    //Example value... myValue = 5
    std::string str;
    while(std::getline(file,str)) {
        if(str.find_first_of("=") != std::string::npos) {
            string whiteSpace = delSpaces(str);
            return atoi(whiteSpace.substr(whiteSpace.find_first_of("=")+1).c_str());
        }
    }
    return -1; //We didn't find a value.
}

JoltDataFile::~JoltDataFile() {
    file.close();
}

