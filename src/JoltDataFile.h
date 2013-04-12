/* 
 * File:   JoltDataFile.h
 * Author: Sean McClenaghan
 *
 * Created on February 4, 2013, 9:20 PM
 */

#ifndef JOLTDATAFILE_H
#define	JOLTDATAFILE_H
#include <iostream>
#include <fstream>

class JoltDataFile {
public:
    JoltDataFile(const char* filename);
    int getInt(const char* prop);
    std::string getString(const char* prop);
    bool getBoolean(const char* prop);
    virtual ~JoltDataFile();
private:
    std::fstream file;
};

#endif	/* JOLTDATAFILE_H */

