/* 
 * File:   JoltApp.h
 * Author: Sean McClenaghan
 *
 * Created on February 4, 2013, 7:13 PM
 */

#ifndef JOLTAPP_H
#define	JOLTAPP_H

#include "SDLStuff.h"
#include "JoltEntity.h"
#include "JoltPlayer.h"

class JoltApp {
public:
    JoltPlayer p1;
    JoltPlayer p2;
public:
    JoltApp();
    int doExecute();
private:
    bool running;    
    SDL_Surface* display;
public:
    bool doInit();
    void onEvent(SDL_Event* evt);
    void onLoop();
    void onRender();
    void doCleanup();
public:
    virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
};

#endif	/* JOLTAPP_H */

