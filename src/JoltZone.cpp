/* 
 * File:   JoltZone.cpp
 * Author: cyberkitsune
 * 
 * So this one needs some explaining...
 * 
 * A "JoltZone" as a cluster of maps. Think Megaman / Zelda Style.
 * Our camera class utilizes this to pan and such. At the moment for debug,
 * only 4 maps are currently rendered at a time.
 * 
 * More to come.
 */

#include <vector>

#include "JoltZone.h"
#include "DrawMacros.h"

JoltZone JoltZone::zoneControl;

JoltZone::JoltZone() {
    areaSize = 0;
}

bool JoltZone::load(char* file) {
    maps.clear();
    
    FILE* fileH = fopen(file, "r");
    
    if(fileH == NULL) {
        //NOPE
        return false;
    }
    
    char tilesetFile[255];
    
    fscanf(fileH, "%s\n", tilesetFile);
    
    if((sTileset = DrawMacros::loadImage(tilesetFile)) == false) {
        fclose(fileH);
        
        return false;
    }
    
    fscanf(fileH, "%d\n", &areaSize);
    
    for (int X = 0; X < areaSize; X++) {
        for (int Y = 0; Y < areaSize; Y++) {
            char mapFile[255];
            
            fscanf(fileH, "%s ", mapFile);
            
            JoltMap tempMap;
            if(tempMap.load(mapFile) == false) {
                fclose(fileH);
                
                return false;
            }
            
            tempMap.sTileset = sTileset;
            maps.push_back(tempMap);
        }
        fscanf(fileH,"\n");


    }
    fclose(fileH);
    
    return true;
    
}

void JoltZone::onRender(SDL_Surface* sDisplay, int camX, int camY) {
    int mapWidth = MAP_WIDTH * TILE_SIZE;
    int mapHeight = MAP_HEIGHT * TILE_SIZE;
    
    int FirstID = -camX / mapWidth;
        FirstID = FirstID + ((-camY / mapHeight) * areaSize);
        
        for (int i = 0; i < 4; i++) {
            int ID = FirstID + ((i / 2) * areaSize) + (i % 2);
            
            if(ID < 0 || ID >= maps.size()) continue;
            
            int x = ((ID % areaSize) * mapWidth) + camX;
            int y = ((ID / areaSize) * mapHeight) + camY;
            
            maps[ID].onRender(sDisplay,x,y);
    }

}

void JoltZone::onCleanup() {
    if(sTileset) {
        SDL_FreeSurface(sTileset);
    }
    
    maps.clear();
}