/* 
 * File:   JoltTile.h
 * Author: cyberkitsune
 *
 * Created on February 6, 2013, 7:38 PM
 */

#ifndef JOLTTILE_H
#define	JOLTTILE_H

#include "defines.h"

enum {
    TILE_TYPE_NONE = 0,
    
    TILE_TYPE_NORMAL,
    TIME_TYPE_BLOCK
};

class JoltTile {
public:
    int tileID;
    int typeID;
    
public:
    JoltTile();

};

#endif	/* JOLTTILE_H */

