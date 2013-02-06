#include "JoltApp.h"

void JoltApp::doCleanup() {
    
    for (int i = 0; i < JoltEntity::entList.size(); i++) {
        if (!JoltEntity::entList[i]) continue; // Let's hope this never happens anyway

        JoltEntity::entList[i]->onCleanup();
    }
    
    SDL_Quit();
}
