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

#include "gTexture.h"
#include "Gevents.hpp"
#include "fist.hpp"
#include "foot.hpp"
#include "stance.hpp"

class player: public Gevents{
public:
    player();
    player(const player& orig);
    virtual ~player();
    
    bool setup( SDL_Renderer* passedScreen, int x, int y);
    
    void stepRight();
    
    void stepLeft(); 
    
    void punch();
    
    void kick();
    
    void reset();
    
    void operate();
    
    void OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode);
    
    void render();
    
    bool moveLeft;
    
    bool moveRight;
    
    fist puncher;
    
    foot shoe;
    
protected:
    
    bool faceLeft;
    
    bool firstPunch;
    
    bool kicking;
    
    short state;
    
    SDL_Rect coords;
    
    short actionState;
    
    short damageType;
    
    short moveSpeed;
    
    short keys[7];
    
    SDL_Rect frames[8];
    
    gTexture image;
    
    SDL_Renderer* screen;
private:

};

#endif	/* PLAYER_HPP */

