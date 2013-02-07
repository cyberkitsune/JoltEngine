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

    if (file.fail()) {
        JoltConsole::logInfo("File", "Failed file %s!", filename);
    }

    if (file.bad()) {
        JoltConsole::logInfo("File", "Bad file %s!", filename);
    }
}

string delSpaces(string &str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int JoltDataFile::getInt(const char* prop) {
    file.seekg(0, ios::beg); //Make sure we're ready to read it from the top.
    //May not be the best way of doing this...
    //Example value... myValue = 5
    std::string str;
    std::string sProp = prop;

    while (std::getline(file, str)) {
        if (str.substr(0, sProp.size()) == sProp) {
            if (str.find_first_of("=") != std::string::npos) {
                string whiteSpace = delSpaces(str);
                return atoi(whiteSpace.substr(whiteSpace.find_first_of("=") + 1).c_str());
            }
        }
    }
    return -1; //We didn't find a value.
}

const char* JoltDataFile::getString(const char* prop) {
    file.seekg(0, ios::beg); //Make sure we're ready to read it from the top.

    std::string str;
    std::string sProp = prop;
    while (std::getline(file, str)) {
        if (str.substr(0, sProp.size()) == prop) {
             if (str.find_first_of("=") != std::string::npos) {
                 printf("%s\n",str.c_str());
                 int posToDo = str.find_first_of('"') + 1;
                 int size = str.size();
                 std::string afterMath = str.substr(posToDo);
                return afterMath.c_str();
            }
        }
    }
    printf("%s\n",str.c_str());
    return NULL; // No string for you :c
}

JoltDataFile::~JoltDataFile() {
    file.close();
}

