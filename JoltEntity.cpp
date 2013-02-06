/* 
 * File:   JoltEntity.cpp
 * Author: cyberkitsune
 * 
 * Created on February 5, 2013, 5:15 PM
 */

#include "JoltEntity.h"

std::vector<JoltEntity*> JoltEntity::entList;

JoltEntity::JoltEntity() {
    
    sEntity = NULL;
    X = Y = 0.0f;
    width = height = 0;
    aniState = 0;
    
}


JoltEntity::~JoltEntity() {
}

bool JoltEntity::loadEnt(char* file, int width, int height, int maxFrames) {
    if((sEntity = DrawMacros::loadImage(file)) == NULL) {
        return false;
    }
    
    DrawMacros::transparent(sEntity, 255, 0, 255);
    
    this->width = width;
    this->height = height;
    
    animationControl.maxFrames = maxFrames;
    
    return true;
}

void JoltEntity::onLoop() {
    animationControl.doAnimate();
}
void JoltEntity::onRender(SDL_Surface* display) {
    if( sEntity == NULL || display == NULL) return;
    
    DrawMacros::doDraw(display, sEntity, X, Y, aniState * width, animationControl.getCurrentFrame() * height, width, height);
}

void JoltEntity::onCleanup() {
    if(sEntity) {
        SDL_FreeSurface(sEntity);
    }
    
    sEntity = NULL;
}