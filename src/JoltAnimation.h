/* 
 * File:   JoltAnimation.h
 * Author: Sean McClenaghan
 *
 * Created on February 5, 2013, 4:36 PM
 */

#ifndef JOLTANIMATION_H
#define	JOLTANIMATION_H

#include "SDLStuff.h"

class JoltAnimation {
public:
    JoltAnimation();
    void doAnimate();
    void setFrameRate(int rate);
    void setCurrentFrame(int frame);
    int getCurrentFrame();
private:
    int frameRate; //in ms
    int frameInc;
    int currentFrame;
    long oldTime;
public:
    int maxFrames;
    bool osc;
    

};

#endif	/* JOLTANIMATION_H */

