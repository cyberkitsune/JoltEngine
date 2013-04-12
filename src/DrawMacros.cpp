/* 
 * File:   DrawMacros.cpp
 * Author: Sean McClenaghan
 * 
 * Created on February 5, 2013, 4:52 PM
 */

#include "DrawMacros.h"

DrawMacros::DrawMacros() {
}

//SDL_Surface* DrawMacros::loadImage(char* file) { //TODO: Work on this
//    SDL_Surface* sTemp = NULL;
//    SDL_Surface* sReturn = NULL;
//    
//    if((sTemp = SDL_LoadBMP(file)) == NULL) {
//        return NULL;
//    }
//    
//    sReturn = SDL_DisplayFormat(sTemp);
//    SDL_FreeSurface(sTemp);
//    
//    return sReturn;
//}

SDL_Surface* DrawMacros::loadImage(char* file) {
    SDL_Surface* sTemp = NULL;
    SDL_Surface* sReturn = NULL;
    
    if((sTemp = IMG_Load(file)) == NULL) {
        return NULL;
    }
    
    if(sTemp->format->Amask) {
        sReturn = SDL_DisplayFormatAlpha(sTemp);
    } else {
        sReturn = SDL_DisplayFormat(sTemp);
    }
    SDL_FreeSurface(sTemp);
    
    return sReturn;
}

bool DrawMacros::doDraw(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y) {
    if(sDest == NULL || sSrc == NULL) {
        return false;
    }
    
    SDL_Rect destRect;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_BlitSurface(sSrc, NULL, sDest, &destRect);
    
    return true;
}

bool DrawMacros::doDraw(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y, int x2, int y2, int w, int h) {
    if(sDest == NULL || sSrc == NULL) {
        return false;
    }
    
    SDL_Rect destRect;
    
    destRect.x = x;
    destRect.y = y;
    
    SDL_Rect cropRect;
    
    cropRect.x = x2;
    cropRect.y = y2;
    cropRect.w = w;
    cropRect.h = h;
    
    SDL_BlitSurface(sSrc, &cropRect, sDest, &destRect);
    
    return true;
}

bool DrawMacros::transparent(SDL_Surface* sDst, int R, int G, int B) {
    if(sDst == NULL) {
        return false;
    }
    
    SDL_SetColorKey(sDst, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(sDst->format,R,G,B));
    
    return true;
}