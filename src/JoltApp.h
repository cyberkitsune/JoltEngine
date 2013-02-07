/* 
 * File:   JoltApp.h
 * Author: cyberkitsune
 *
 * Created on February 4, 2013, 7:13 PM
 */

#ifndef JOLTAPP_H
#define	JOLTAPP_H

#include "SDLStuff.h"
#include "JoltEntity.h"

class JoltApp {
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
};

#endif	/* JOLTAPP_H */

