/* 
 * File:   JoltAnimation.cpp
 * Author: cyberkitsune
 * 
 * Created on February 5, 2013, 4:36 PM
 */

#include "JoltAnimation.h"

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
        return; // We aren't ready to go to the next frame, so nothing should happen.
    }
    
    oldTime = SDL_GetTicks();
    
    currentFrame += frameInc;
    
    if(osc) {
        if(frameInc > 0) {
            if(currentFrame >= maxFrames) {
                frameInc = -frameInc;
            }
        } else {
            if(currentFrame <= 0) {
                frameInc = -frameInc;
            }
        }
    } else {
        if(currentFrame >= maxFrames) {
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