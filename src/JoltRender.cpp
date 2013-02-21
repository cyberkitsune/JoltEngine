#include "JoltApp.h"
#include "JoltZone.h"
#include "JoltCamera.h"
#include "JoltConsole.h"


void JoltApp::onRender() {

    SDL_Rect rBlank = {0,0,WWIDTH,WHEIGHT};
    SDL_FillRect(display,&rBlank,0x000000);
    // Draw maps first
    JoltZone::zoneControl.onRender(display, -JoltCamera::viewController.getX(), -JoltCamera::viewController.getY());
    for (int i = 0; i < JoltEntity::entList.size(); i++) {
        if (!JoltEntity::entList[i]) continue; // Let's hope this never happens anyway

        JoltEntity::entList[i]->onRender(display);
    }
    
    SDL_Flip(display);

}
