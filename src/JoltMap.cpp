/* 
 * File:   JoltMap.cpp
 * Author: Sean McClenaghan
 * 
 * Created on February 6, 2013, 7:47 PM
 */

#include <vector>
#include <stdio.h>

#include "JoltMap.h"
#include "DrawMacros.h"

JoltMap::JoltMap() {
    //Init the tileset
    sTileset = NULL;
}

bool JoltMap::load(char* file) {
    tileList.clear();

    FILE* fileH = fopen(file, "r");

    if (fileH == NULL) {
        // Shit went wrong
        return false;
    }

    // GOTTA MOVE THAT GEAR UP
    for (int Y = 0; Y < MAP_HEIGHT; Y++) {
        for (int X = 0; X < MAP_WIDTH; X++) {
            JoltTile tempTile;

            fscanf(fileH, "%d:%d ", &tempTile.tileID, &tempTile.typeID);
            tileList.push_back(tempTile);

        }
        fscanf(fileH, "\n");

    }
    fclose(fileH);
    
    return true;
}

// Here goes nothing...
// FASTEN YOUR SEATBELTS
void JoltMap::onRender(SDL_Surface* sDisplay, int mapX, int mapY) {
    if(sTileset == NULL) return; // We've gone too far, but we can't continue...
    
    int tilesetWidth = sTileset->w / TILE_SIZE;
    //int tilesetHeight = sTileset->h / TILE_SIZE; // Don't need this.
    
    int ID = 0;
    
    for (int Y = 0; Y < MAP_HEIGHT; Y++) {
        for (int X = 0; X < MAP_WIDTH; X++) {
            if(tileList[ID].typeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }

            int tX = mapX + (X * TILE_SIZE);
            int tY = mapY + (Y * TILE_SIZE);
            
            int tilesetX = (tileList[ID].tileID % tilesetWidth) * TILE_SIZE;
            int tilesetY = (tileList[ID].tileID / tilesetWidth) * TILE_SIZE;

            DrawMacros::doDraw(sDisplay, sTileset, tX, tY, tilesetX, tilesetY, TILE_SIZE, TILE_SIZE);
            
            ID++;
        }

    }
   
}

JoltTile* JoltMap::getTile(int X, int Y) {
    int ID = 0;
    
    ID = X / TILE_SIZE;
    ID = ID + (MAP_WIDTH * (Y/ TILE_SIZE));
    
    if(ID < 0 || ID  >= tileList.size()) {
        return NULL;
    }
    
    return &tileList[ID];
}