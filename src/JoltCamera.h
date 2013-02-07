/* 
 * File:   JoltCamera.h
 * Author: cyberkitsune
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
    int x;
    int y;
    // Ohnoes pointers incoming
    int* targetX;
    int* targetY;
    
public:
    int tMode;
    
public:
    JoltCamera();

public:
    void onMove(int movX, int movY);
    
public:
    int getX();
    int getY();
    
public:
    void setPos(int x, int y);
    void setTarget(int* x, int* y);
};

#endif	/* JOLTCAMERA_H */


