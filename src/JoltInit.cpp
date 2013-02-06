#include "JoltApp.h"
#include "JoltConsole.h"
#include <stdlib.h>

/**
 * Init Script
 * 
 */
bool JoltApp::doInit() {
    JoltConsole::logInfo("Init", "Init started.");
    if(SDL_Init(SDL_INIT_EVERYTHING)) {
        JoltConsole::logInfo("Init", "SDL INIT FAIL!"); //TODO: Make logError
        return false;
    }
    JoltConsole::logInfo("Init", "SDL Init Complete");
    
    if((display = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        JoltConsole::logInfo("Init", "Unable to create screen!");
        return false;
    }
    JoltConsole::logInfo("Init", "Screen initilized.");
    return true;
}