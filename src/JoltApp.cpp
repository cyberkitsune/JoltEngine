/* 
 * File:   JoltApp.cpp
 * Author: Sean McClenaghan
 * 
 * Created on February 4, 2013, 7:13 PM
 */

#include "JoltApp.h"
#include "SDLStuff.h"
#include "JoltConsole.h"

JoltApp::JoltApp() {
    display = NULL;
    running = true;
}

int JoltApp::doExecute() {
    
    if(!doInit()) {
        return -1;
    }
    
    SDL_Event evt;
    
    JoltConsole::logInfo("App","Starting game loop.");
    while(running) {
        while(SDL_PollEvent(&evt)) {
            onEvent(&evt);
        }
        
        onLoop();
        onRender();
        //JoltConsole::logInfo("Main","Loop called at %i", SDL_GetTicks());
    }
    
    doCleanup();
    
    return 0;
    
}

int main() {
    JoltApp application;
    JoltConsole::logInfo("Main", "Starting JoltApp v0");
    return application.doExecute();
}