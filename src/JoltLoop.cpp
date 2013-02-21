#include <vector>

#include "JoltApp.h"
#include "Framerate.h"


void JoltApp::onLoop() {
    // Entities
    for(int i=0; i < JoltEntity::entList.size(); i++) {
        if(!JoltEntity::entList[i]) continue; // Let's hope this never happens anyway
        
        JoltEntity::entList[i]->onLoop();
    }
    
    //Collision events
    for (int i = 0; i < JoltEntityCol::entColList.size(); i++) {
        JoltEntity* entA = JoltEntityCol::entColList[i].entA;
        JoltEntity* entB = JoltEntityCol::entColList[i].entB;
        
        if(entA == NULL || entB == NULL) continue;
        
        if(entA->onCollision(entB)) {
            entB->onCollision(entA);
        }

    }

    JoltEntityCol::entColList.clear();
    
    Framerate::fcontrol.onLoop();
    
    char buf[225];
    sprintf(buf, "JoltApp FPS: %d", Framerate::fcontrol.getFPS());
    SDL_WM_SetCaption(buf,buf);
    
}
