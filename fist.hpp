/* 
 * File:   fist.hpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:37 PM
 */

#ifndef FIST_HPP
#define	FIST_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class fist{
public:
    fist();
    fist(const fist& orig);
    virtual ~fist();
    
    void update(int a, int b);
    
    short getFistX();
    
    short getFistY();
    
    void render(SDL_Renderer* screen);

private:
    SDL_Rect coords;
};

#endif	/* FIST_HPP */

