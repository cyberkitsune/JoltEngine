/* 
 * File:   JoltCamera.cpp
 * Author: cyberkitsune
 * 
 * Created on February 6, 2013, 8:38 PM
 */

#include "JoltCamera.h"
#include "defines.h"

JoltCamera JoltCamera::viewController;

JoltCamera::JoltCamera() {
    x = y = 0;
    
    targetX = targetY = NULL;
    
    tMode = TARGET_MODE_NORMAL;
}

void JoltCamera::onMove(int movX, int movY) {
    x += movX;
    y += movY;
}

float JoltCamera::getX() {
    if(targetX != NULL) {
        if(tMode == TARGET_MODE_CENTER) {
            return *targetX - (WWIDTH / 2);
        }
        
        return *targetX;
    }
    return x;
    
}

float JoltCamera::getY() {
    if(targetY != NULL) {
        if(tMode == TARGET_MODE_CENTER) {
            return *targetY - (WHEIGHT / 2);
        }
        
        return *targetY;
    }
    return y;
    
}

void JoltCamera::setPos(float x, float y) {
    this->x = x;
    this->y = y;
}

void JoltCamera::setTarget(float* x, float* y) {
    targetX = x;
    targetY = y;
}