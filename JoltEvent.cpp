#include "JoltApp.h"
#include "JoltConsole.h"

void JoltApp::onEvent(SDL_Event* evt) {
    JoltConsole::logInfo("Event", "Caught event code %i",evt->type);
}