/* 
 * File:   JoltEntityCol.cpp
 * Author: Sean McClenaghan
 * 
 * Created on February 20, 2013, 6:25 PM
 */

#include <vector>

#include "JoltEntity.h"

std::vector<JoltEntityCol> JoltEntityCol::entColList;

JoltEntityCol::JoltEntityCol() {
    this->entA = NULL;
    this->entB = NULL;
}

