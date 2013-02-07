/* 
 * File:   JoltMap.h
 * Author: cyberkitsune
 *
 * Created on February 6, 2013, 7:47 PM
 */

#ifndef JOLTMAP_H
#define	JOLTMAP_H

#include "JoltTile.h"
#include "SDLStuff.h"


class JoltMap {
public:
    SDL_Surface* sTileset;
    
private:
    std::vector<JoltTile> tileList;
    
public:
    JoltMap();

public:
    bool load(char* file);
    void onRender(SDL_Surface* sDisplay, int mapX, int mapY);
};

#endif	/* JOLTMAP_H */

