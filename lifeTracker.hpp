/* 
 * File:   lifeTracker.hpp
 * Author: garys
 *
 * Created on March 28, 2016, 10:38 AM
 */

#ifndef LIFETRACKER_HPP
#define	LIFETRACKER_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"

class lifeTracker {
public:
    lifeTracker();
    lifeTracker(const lifeTracker& orig);
    virtual ~lifeTracker();
    
    void place(int a, int b);
    
    void reduce(int damage);
    
    void render(SDL_Renderer* screen);
    
private:
    SDL_Rect coords;
    
    SDL_Color color;
    
    short amount;
};

#endif	/* LIFETRACKER_HPP */

