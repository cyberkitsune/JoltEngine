/* 
 * File:   JoltPlayer.h
 * Author: Sean McClenaghan
 *
 * Created on February 20, 2013, 5:33 PM
 */

#ifndef JOLTPLAYER_H
#define	JOLTPLAYER_H

#include "JoltEntity.h"


class JoltPlayer : public JoltEntity{
public:
    JoltPlayer();
    bool loadEnt(char* file, int width, int height, int maxFrames);
    void onLoop();
    void onRender(SDL_Surface* sDisp);
    void onCleanup();
    void onAnimate();
    bool onCollision(JoltEntity* ent);

};

#endif	/* JOLTPLAYER_H */

