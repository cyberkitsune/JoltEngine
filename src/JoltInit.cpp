#include "JoltApp.h"
#include "JoltConsole.h"
#include "JoltDataFile.h"
#include "defines.h"
#include "JoltZone.h"
#include "JoltCamera.h"
#include <stdlib.h>
#include <vector>

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
    
    if((display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        JoltConsole::logInfo("Init", "Unable to create screen!");
        return false;
    }
    JoltConsole::logInfo("Init", "Screen initilized.");
    SDL_WM_SetCaption("A Jolt Engine Application",NULL);
    
    //int numResources = 0;
    //JoltConsole::logInfo("Init", "Begin resource loading. Going to load %i resources", numResources);
    //int loadedResources = 0;
    
    /*
     * Here we'll do resource discovery, prolly via a global resources.ini
     * resources.ini example:
     * player plr = player.ini
     * map default = default.ini
     * map level1 = l1.ini
     * etc
     * level inis will have entities? and will increment the resource counter.
     */
    //JoltConsole::logInfo("Init", "Resource loading complete. Loeaded %i resources successfully.", loadedResources);
    if(JoltZone::zoneControl.load("./res/testarea.zone") == false) {
        JoltConsole::logInfo("Init", "Unable to load test zone!");
        return false;
    }
    
    //SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
    
    JoltConsole::logInfo("Init","Loading players.");
    if(p1.loadEnt("./res/yoshi.png", 64, 64, 8) == false) {
        return false;
    }
    
    if(p2.loadEnt("./res/yoshi.png", 64, 64, 8) == false) {
        return false;
    }
    
    p2.X = 100;
    
    JoltEntity::entList.push_back(&p1);
    JoltEntity::entList.push_back(&p2);
    
    // Set camera
    JoltCamera::viewController.tMode = TARGET_MODE_CENTER;
    JoltCamera::viewController.setTarget(&p1.X,&p1.Y); // C++ is magic. When X and Y get modified in another class/scope, they change
                                                       // in JoltCamera too due to pointers. Woo!
    
    return true;
}