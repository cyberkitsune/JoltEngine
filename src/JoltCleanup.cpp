#include "JoltApp.h"
#include "JoltConsole.h"
#include "JoltZone.h"

void JoltApp::doCleanup() {
    
    JoltConsole::logInfo("Init", "Starting cleanup.");
    
    JoltConsole::logInfo("Cleanup", "Cleaning %i entities.", JoltEntity::entList.size());
    for (int i = 0; i < JoltEntity::entList.size(); i++) {
        if (!JoltEntity::entList[i]) continue; // Let's hope this never happens anyway

        JoltEntity::entList[i]->onCleanup();
    }
    JoltConsole::logInfo("Cleanup", "Entities all clean :3");
    JoltConsole::logInfo("Cleanup", "Cleaning maps and zones...");
    JoltZone::zoneControl.onCleanup();
    JoltConsole::logInfo("Cleanup", "Maps and Zones clean.");
    
    JoltConsole::logInfo("Init", "Cleanup complete.");
    
    SDL_Quit();
}
