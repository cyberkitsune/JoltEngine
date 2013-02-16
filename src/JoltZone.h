/* 
 * File:   JoltZone.h
 * Author: cyberkitsune
 *
 * Created on February 6, 2013, 8:12 PM
 */

#ifndef JOLTZONE_H
#define	JOLTZONE_H

#include "JoltMap.h"


class JoltZone {
public:
    static JoltZone             zoneControl;
public:
    std::vector<JoltMap>        maps;
    
private:
    int                         areaSize;
    
    SDL_Surface*                sTileset;
public:
    JoltZone();
    
    bool load(char* file);
    void onRender(SDL_Surface* sDisplay, int camX, int camY);
    void onCleanup();
public:
    JoltMap* getMap(int X, int Y);
    JoltTile* getTile(int X, int Y);


};

#endif	/* JOLTZONE_H */

