/* 
 * File:   JoltEntity.h
 * Author: Sean McClenaghan
 *
 * Created on February 5, 2013, 5:15 PM
 */

#ifndef JOLTENTITY_H
#define	JOLTENTITY_H

#include <vector>

#include "JoltAnimation.h"
#include "DrawMacros.h"
#include "JoltTile.h"

enum {
    ENTITY_TYPE_GENERIC = 0,
 
    ENTITY_TYPE_PLAYER
};
 
enum {
    ENTITY_FLAG_NONE     = 0,
 
    ENTITY_FLAG_GRAVITY    = 0x00000001,
    ENTITY_FLAG_GHOST    = 0x00000002,
    ENTITY_FLAG_MAPONLY    = 0x00000004
};
 

class JoltEntity {
public:
    static std::vector<JoltEntity*>  entList;
    
protected:
    JoltAnimation animationControl;
    SDL_Surface* sEntity;
public:
    float       X;
    float       Y;
    
    int         width;
    int         height;
    
    bool moveLeft;
    bool moveRight;
    
    //int         aniState;
public:
    int type;
    bool dead;
    int flags;
protected:
    float velX;
    float velY;
    bool canJump;
    float accelX;
    float accelY;
public:
    float maxVelX;
    float maxVelY;
protected:
    int curFrameCol;
    int curFrameRow;
protected:
    int colX;
    int colY;
    int colWide;
    int colTall;
public:
    JoltEntity();
    
    virtual ~JoltEntity();
public:
    virtual bool loadEnt(char* file, int width, int height, int maxFrames);
    virtual void onLoop();
    virtual void onRender(SDL_Surface* display);
    virtual void onCleanup();
    virtual void onAnimate();
    virtual bool onCollision(JoltEntity* ent);
public:
    void onMove(float movX, float movY);
    void stopMove();
    bool jump();
public:
    bool collides(int oX, int oY, int oW, int oH);
private:
    bool posValid(int newX, int newY);
    bool posValidTile(JoltTile* tile);
    bool posValidEnt(JoltEntity* ent, int newX, int newY);

};

class JoltEntityCol {
public:
    static std::vector<JoltEntityCol> entColList;
    
public:
    JoltEntity* entA;
    JoltEntity* entB;
    
public:
    JoltEntityCol();
};

#endif	/* JOLTENTITY_H */

