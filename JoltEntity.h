/* 
 * File:   JoltEntity.h
 * Author: cyberkitsune
 *
 * Created on February 5, 2013, 5:15 PM
 */

#ifndef JOLTENTITY_H
#define	JOLTENTITY_H

#include <vector>

#include "JoltAnimation.h"
#include "DrawMacros.h"

class JoltEntity {
public:
    static std::vector<JoltEntity*>  entList;
    
protected:
    JoltAnimation animationControl;
    SDL_Surface* sEntity;
public:
    float       X;
    float       Y;
    
    int         width;
    int         height;
    
    int         aniState;
public:
    JoltEntity();
    
    virtual ~JoltEntity();
public:
    virtual bool loadEnt(char* file, int width, int height, int maxFrames);
    virtual void onLoop();
    virtual void onRender(SDL_Surface* display);
    virtual void onCleanup();

};

#endif	/* JOLTENTITY_H */

