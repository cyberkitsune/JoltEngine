/* 
 * File:   JoltAnimation.cpp
 * Author: Sean McClenaghan
 * 
 * Created on February 5, 2013, 4:36 PM
 */

#include "JoltAnimation.h"
#include "JoltConsole.h"

JoltAnimation::JoltAnimation() {
    currentFrame = 0;
    maxFrames = 0;
    frameInc = 1;
    
    frameRate =  100; //ms
    oldTime = 0;
    
    osc = false; 
    
}

void JoltAnimation::doAnimate() {
 if(oldTime + frameRate > SDL_GetTicks()) {
        return;
    }

    oldTime = SDL_GetTicks();

    currentFrame += frameInc;

    if(osc) {
        if(frameInc > 0) {
            if(currentFrame >= maxFrames - 1) {
                frameInc = -frameInc;
            }
        }else{
            if(currentFrame <= 0) {
                frameInc = -frameInc;
            }
        }
    }else{
        if(currentFrame >= maxFrames - 1) {
            currentFrame = 0;
        }
    }
}

void JoltAnimation::setFrameRate(int rate) {
    frameRate = rate;
}

void JoltAnimation::setCurrentFrame(int frame) {
    if(frame < 0 || frame >= maxFrames) return;
    
    currentFrame = frame;
}

int JoltAnimation::getCurrentFrame() {
    return currentFrame;
}