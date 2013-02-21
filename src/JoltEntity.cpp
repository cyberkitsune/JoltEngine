/* 
 * File:   JoltEntity.cpp
 * Author: cyberkitsune
 * 
 * Created on February 5, 2013, 5:15 PM
 */

#include "JoltEntity.h"
#include "Framerate.h"
#include "JoltCamera.h"
#include "JoltZone.h"
#include "JoltConsole.h"

std::vector<JoltEntity*> JoltEntity::entList;

JoltEntity::JoltEntity() {
    
    sEntity = NULL;
    X = Y = 0.0f;
    width = height = 0;
    
    moveLeft = false;
    moveRight = false;
    
    type = ENTITY_TYPE_GENERIC;
    
    dead = false;
    flags = ENTITY_FLAG_GRAVITY;
    
    velX = 0;
    velY = 0;
    accelX = 0;
    accelY = 0;
    
    maxVelX = 10;
    maxVelY = 10;
    
    curFrameCol = 0;
    curFrameRow = 0;
    
    colX = 0;
    colY = 0;
    
    colWide = 0;
    colTall = 0;
    
    canJump = false;
    
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
    //If we're not moving...
    if(!moveLeft && !moveRight) {
        stopMove();
    }
    
    if(moveLeft) {
        accelX = -0.5;
    } else if(moveRight) {
        accelX = 0.5;
    }
    
    if(flags & ENTITY_FLAG_GRAVITY) {
        accelY = 0.75f;
    }
    
    velX += accelX * Framerate::fcontrol.getSpeedFactor();
    velY += accelY * Framerate::fcontrol.getSpeedFactor();
    
    if(velX > maxVelX) velX = maxVelX; // Clamp faster speed.
    if(velX < -maxVelX) velX = -maxVelX;
    if(velY > maxVelY) velY = maxVelY; // Clamp faster speed.
    if(velY < -maxVelY) velY = -maxVelY;
    
    onAnimate();
    onMove(velX, velY);
    
}
void JoltEntity::onRender(SDL_Surface* display) {
    if( sEntity == NULL || display == NULL) return;
    
    DrawMacros::doDraw(display, sEntity, X - JoltCamera::viewController.getX(), Y - JoltCamera::viewController.getY(), curFrameCol * width, (curFrameRow * animationControl.getCurrentFrame()) * height, width, height);
}

void JoltEntity::onCleanup() {
    if(sEntity) {
        SDL_FreeSurface(sEntity);
    }
    
    sEntity = NULL;
}

void JoltEntity::onAnimate() {
    if(moveLeft) {
        curFrameCol = 0;
    } else if(moveRight) {
        curFrameCol = 1;
    }
    
    animationControl.doAnimate();
}

bool JoltEntity::onCollision(JoltEntity* ent) {
}

void JoltEntity::onMove(float movX, float movY) {
    if(movX == 0 && movY == 0) return;
    
    //JoltConsole::logInfo("Info","An entity is moving.");
    
    double newX = 0;
    double newY = 0;
    
    movX *= Framerate::fcontrol.getSpeedFactor();
    movY *= Framerate::fcontrol.getSpeedFactor();
    
    if(movX != 0) {
        if(movX >= 0)   newX = Framerate::fcontrol.getSpeedFactor();
        else            newX = -Framerate::fcontrol.getSpeedFactor();
    }
    
    if(movY != 0) {
        if(movY != 0)   newY = Framerate::fcontrol.getSpeedFactor();
        else            newY = -Framerate::fcontrol.getSpeedFactor();
    }
    
    while(true) {
		if(flags & ENTITY_FLAG_GHOST) {
			posValid((int)(X + newX), (int)(Y + newY)); //We don't care about collisions, but we need to send events to other entities

			X += newX;
			Y += newY;
		}else{
			if(posValid((int)(X + newX), (int)(Y))) {
				X += newX;
			}else{
				velX = 0;
			}

			if(posValid((int)(X), (int)(Y + newY))) {
				Y += newY;
			}else{
                if(movY > 0) {
                    canJump = true;
                }

				velY = 0;
			}
		}

		movX += -newX;
		movY += -newY;

		if(newX > 0 && movX <= 0) newX = 0;
		if(newX < 0 && movX >= 0) newX = 0;

		if(newY > 0 && movY <= 0) newY = 0;
		if(newY < 0 && movY >= 0) newY = 0;

		if(movX == 0) newX = 0;
		if(movY == 0) newY = 0;

		if(movX == 0 && movY 	== 0) 	break;
		if(newX  == 0 && newY 	== 0) 	break;
	}   
}

bool JoltEntity::jump() {
    if(!canJump) return false;
    JoltConsole::logInfo("Jump","Tried to jump!");
    
    velY = 50;
    
    return true;
}

void JoltEntity::stopMove() {
    if(velX > 0) {
        accelX = -1;
    }
    
    if(velX < 0) {
        accelX = 1;
    }
    
    if(velX < 2.0f && velX > -2.0f) {
        accelX = 0;
        velX = 0;
    }
}

bool JoltEntity::collides(int oX, int oY, int oW, int oH) {
    int l1, l2;
    int r1, r2;
    int t1, t2;
    int b1, b2;
    
    int tX = (int)X + colX;
    int tY = (int)Y + colY;
    
    l1 = tX;
    l2 = oX;
    
    r1 = l1 + width - 1 - colWide;
    r2 = oX + oW - 1;
    
    t1 = tY;
    t2 = oY;
    
    b1 = t1 + height - 1 - colTall;
    b2 = oY + oH - 1;
   
    if(b1 < t2) return false;
    if(t1 > b2) return false;
    
    if(r1 < l2) return false;
    if(l1 > r2) return false;
    
    return true;
    
}

bool JoltEntity::posValid(int newX, int newY) {
    bool ret = true;
    
    int sX =  (newX + colX) / TILE_SIZE;
    int sY =  (newY + colY) / TILE_SIZE;
    
    int eX = ((newX + colX) + width - colWide - 1)      /TILE_SIZE;
    int eY = ((newY + colY) + height - colTall -  1)    /TILE_SIZE;
    
    for(int iY = sY; iY <= eY; iY++) {
        for(int iX = sX; iX <= eX; iX++) {
            JoltTile* tile = JoltZone::zoneControl.getTile(iX * TILE_SIZE, iY * TILE_SIZE);
            
            if(posValidTile(tile) == false) {
                ret = false;
            }
        }
    }
    
    if(flags & ENTITY_FLAG_MAPONLY) {
    } else {
        for(int i = 0; i < entList.size(); i++) {
            if(posValidEnt(entList[i], newX, newY) == false) {
                ret = false;
            }
        }
    }
    
    return ret;
}

bool JoltEntity::posValidTile(JoltTile* tile) {

    if(tile == NULL) {
        return false;
    }
    
    if(tile->typeID == TILE_TYPE_BLOCK) {
        return false;
    }
    
    return true;
}

bool JoltEntity::posValidEnt(JoltEntity* ent, int newX, int newY) {
    if(this != ent && ent != NULL && ent->dead == false &&
            ent->flags ^ ENTITY_FLAG_MAPONLY &&
            ent->collides(newX + colX, newY + colY, width - colWide - 1, height - colTall - 1) == true) {
        JoltEntityCol entCol;
        
        entCol.entA = this;
        entCol.entB = ent;
        
        JoltEntityCol::entColList.push_back(entCol); // Add our entity collision to our new event buffer.
        
        return false;
    }
    
    return true;
}

