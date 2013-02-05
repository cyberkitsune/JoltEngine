/* 
 * File:   JoltDataFile.cpp
 * Author: cyberkitsune
 * 
 * Created on February 4, 2013, 9:20 PM
 */

#include "JoltDataFile.h"

JoltDataFile::JoltDataFile(const char* filename) {
    file.open(filename, std::ios::in);
}

JoltDataFile::~JoltDataFile() {
    file.close();
}

