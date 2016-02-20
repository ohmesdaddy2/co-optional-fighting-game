/* 
 * File:   foot.hpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:37 PM
 */

#ifndef FOOT_HPP
#define	FOOT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "player.hpp"

class foot{
public:
    foot();
    foot(const foot& orig);
    virtual ~foot();
    
    void move(int a, int b);
    
    bool kicking;
    
#ifdef DEBUG_RENDER
    void render(SDL_Renderer* screen);
#endif
private:
    SDL_Rect coords;
};

#endif	/* FOOT_HPP */

