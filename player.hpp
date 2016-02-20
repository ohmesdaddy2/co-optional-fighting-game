/* 
 * File:   player.hpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:37 PM
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "fist.hpp"
#include "foot.hpp"
#include "stance.hpp"

class player{
public:
    player();
    player(const player& orig);
    virtual ~player();
    
    bool setup(SDL_Texture* passedImage, SDL_Renderer* passedScreen, int x, int y);
    
    void moveRight();
    
    void moveLeft(); 
    
    void punch();
    
    void kick();
    
    void reset();
    
    void render();
    
protected:
    
    bool firstPunch;
    
    bool kicking;
    
    short state;
    
    foot shoe;
    
    fist puncher[2];
    
    SDL_Rect coords;
    
    short actionState;
    
    short damageType;
    
    SDL_Rect frames[4];
    
    SDL_Texture* image;
    
    SDL_Renderer* screen;
private:

};

#endif	/* PLAYER_HPP */

