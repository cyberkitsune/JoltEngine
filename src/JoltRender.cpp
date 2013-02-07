#include "JoltApp.h"
#include "JoltZone.h"
#include "JoltCamera.h"


void JoltApp::onRender() {

    // Draw maps first
    JoltZone::zoneControl.onRender(display,JoltCamera::viewController.getX(), JoltCamera::viewController.getY());
    for (int i = 0; i < JoltEntity::entList.size(); i++) {
        if (!JoltEntity::entList[i]) continue; // Let's hope this never happens anyway

        JoltEntity::entList[i]->onRender(display);
    }

}
