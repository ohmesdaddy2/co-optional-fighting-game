/* 
 * File:   bagTest.hpp
 * Author: garys
 *
 * Created on February 29, 2016, 1:35 PM
 */

#ifndef BAGTEST_HPP
#define	BAGTEST_HPP

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"

class bagTest {
public:
    bagTest();
    bagTest(const bagTest& orig);
    virtual ~bagTest();
    
    int getX();
    
    int getY();
    
    int getW();
    
    int getH();
    
    bool struck(int a, int b);
    
    void render(SDL_Renderer* screen);
    
private:
    
    SDL_Rect coords;

};

#endif	/* BAGTEST_HPP */

