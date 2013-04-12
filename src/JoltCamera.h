/* 
 * File:   JoltCamera.h
 * Author: Sean McClenaghan
 *
 * Created on February 6, 2013, 8:38 PM
 */

#ifndef JOLTCAMERA_H
#define	JOLTCAMERA_H

#include "DrawMacros.h"


enum {
    TARGET_MODE_NORMAL = 0, // Think Zelda, Megaman.
    TARGET_MODE_CENTER // Think normal games.
};

class JoltCamera {
public:
    static JoltCamera viewController; // Who wouldn't want this static? ;3
private:
    float x;
    float y;
    // Ohnoes pointers incoming
    float* targetX;
    float* targetY;
    
public:
    int tMode;
    
public:
    JoltCamera();

public:
    void onMove(int movX, int movY);
    
public:
    float getX();
    float getY();
    
public:
    void setPos(float x, float y);
    void setTarget(float* x, float* y);
};

#endif	/* JOLTCAMERA_H */


