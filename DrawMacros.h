/* 
 * File:   DrawMacros.h
 * Author: cyberkitsune
 *
 * Created on February 5, 2013, 4:52 PM
 */

#ifndef DRAWMACROS_H
#define	DRAWMACROS_H

#include "SDLStuff.h"

class DrawMacros {
public:
    DrawMacros();
public:
    static SDL_Surface* loadImage(char* file);
    static bool doDraw(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y);
    static bool doDraw(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y, int x2, int y2, int w, int h); //For multipart surfaces
    static bool transparent(SDL_Surface* sDst, int R, int G, int B);

};

#endif	/* DRAWMACROS_H */

