#include "JoltApp.h"
#include "JoltConsole.h"
#include "JoltCamera.h"

void JoltApp::onEvent(SDL_Event* evt) {
    //JoltConsole::logInfo("Event", "Caught event code %i",evt->type);
    if(evt->type == SDL_QUIT) {
        running = false; //We're outta here!
    } else if(evt->type == SDL_KEYDOWN) {
        onKeyDown(evt->key.keysym.sym,evt->key.keysym.mod,evt->key.keysym.unicode);
    }
}

void JoltApp::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_UP: JoltCamera::viewController.onMove(0, 5); break;
        case SDLK_DOWN: JoltCamera::viewController.onMove(0, -5); break;
        case SDLK_LEFT: JoltCamera::viewController.onMove(5, 0); break;
        case SDLK_RIGHT: JoltCamera::viewController.onMove(-5, 0); break;
    
        default: { 
            
        }
    }
}