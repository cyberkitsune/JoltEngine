/* 
 * File:   Framerate.h
 * Author: Sean McClenaghan
 *
 * Created on February 13, 2013, 7:18 PM
 */

#ifndef FRAMERATE_H
#define	FRAMERATE_H

class Framerate {
public:
    static Framerate fcontrol;
private:
    int oldTime;
    int lastTime;
    
    float speedFactor;
    
    int numFrames;
    int frames;
public:
    Framerate();
    void onLoop();
public:
    int getFPS();    
    float getSpeedFactor();

};

#endif	/* FRAMERATE_H */

