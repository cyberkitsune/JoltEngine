/* 
 * File:   Framerate.cpp
 * Author: cyberkitsune
 * 
 * Created on February 13, 2013, 7:18 PM
 */

#include <SDL/SDL_timer.h>

#include "Framerate.h"

Framerate Framerate::fcontrol;

Framerate::Framerate() {
    oldTime = 0;
    lastTime = 0;
    
    speedFactor = 0;
    
    frames = 0;
    numFrames = 0;
}

void Framerate::onLoop() {
    if(oldTime + 1000 < SDL_GetTicks()) {
        oldTime = SDL_GetTicks();
        numFrames = frames;
        frames = 0;
    }
    
    speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
    
    lastTime = SDL_GetTicks();
    
    frames++;
}

int Framerate::getFPS() {
    return numFrames;
}

float Framerate::getSpeedFactor() {
    return speedFactor;
}