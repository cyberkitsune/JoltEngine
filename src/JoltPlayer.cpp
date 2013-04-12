/* 
 * File:   JoltPlayer.cpp
 * Author: Sean McClenaghan
 * 
 * Created on February 20, 2013, 5:33 PM
 */

#include "JoltPlayer.h"

JoltPlayer::JoltPlayer() {
}

bool JoltPlayer::loadEnt(char* file, int width, int height, int maxFrames) {
    if(JoltEntity::loadEnt(file, width, height, maxFrames) == false) {
        return false;
    }
    return true;
}

void JoltPlayer::onLoop() {
    JoltEntity::onLoop();
}

void JoltPlayer::onRender(SDL_Surface* sDisp) {
    JoltEntity::onRender(sDisp);
}

void JoltPlayer::onCleanup() {
    JoltEntity::onCleanup();
}

void JoltPlayer::onAnimate() {
    if(velX != 0) {
        animationControl.maxFrames = 8; // For yoshi sprite
    } else {
        animationControl.maxFrames = 0;
    }
    
    JoltEntity::onAnimate();
}

bool JoltPlayer::onCollision(JoltEntity* ent) {
    jump();
    
    return true;
}