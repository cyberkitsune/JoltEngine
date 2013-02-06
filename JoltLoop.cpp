#include "JoltApp.h"


void JoltApp::onLoop() {
    /*
     This SHOULD loop though all entites in that vector and run the logic loops.
     
     */
    for(int i=0; i < JoltEntity::entList.size(); i++) {
        if(!JoltEntity::entList[i]) continue; // Let's hope this never happens anyway
        
        JoltEntity::entList[i]->onLoop();
    }
}
