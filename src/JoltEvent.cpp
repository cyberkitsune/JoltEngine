#include "JoltApp.h"
#include "JoltConsole.h"
#include "JoltCamera.h"

void JoltApp::onEvent(SDL_Event* evt) {
    //JoltConsole::logInfo("Event", "Caught event code %i",evt->type);
    if(evt->type == SDL_QUIT) {
        running = false; //We're outta here!
    } else if(evt->type == SDL_KEYDOWN) {
        onKeyDown(evt->key.keysym.sym,evt->key.keysym.mod,evt->key.keysym.unicode);
    } else if(evt->type == SDL_KEYUP) {
        onKeyUp(evt->key.keysym.sym,evt->key.keysym.mod,evt->key.keysym.unicode);
    }
}

void JoltApp::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT:
            p1.moveLeft = true;
            break;
            
        case SDLK_RIGHT:
            p1.moveRight = true;
            break;
        case SDLK_SPACE:
            p1.jump();
            break;
    
        default: {   
        }
    }
}

void JoltApp::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT:
            p1.moveLeft = false;
            break;
        case SDLK_RIGHT:
            p1.moveRight = false;
            break;
            
            
        default: {
        }
        
    }
}