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

	bool getHit(int a, int b);

	//This is a temporary fuction until the menus are implemented
	bool setKeys(int a);
    
    int getX();
    
    int getY();
    
	void control(const Uint8* passedKey);

	void block();

	void unBlock();

    void setDirection(int a);
    
    void stepRight();
    
    void stepLeft();

    void stop();
    
    void punch();
    
    void kick();
    
    void reset();
    
    void operate(int dir, int hitA, int hitB);
    
    void render();
    
    bool moveLeft;
    
    bool moveRight;
    
    fist puncher;
    
    foot shoe;
    
protected:

	lifeTracker healthBar;
    
    bool faceLeft;
    
    bool firstPunch;
    
    bool kicking;

	bool blocking;
    
    short state;
    
    SDL_Rect coords;

	SDL_Rect hitCoords;

    short actionState;
    
    short damageType;
    
    short moveSpeed;

	short actionResetTime;

	short playerNumber;

    /*This is the array for the controls
		key 0 = Move Left
		key 1 = Move Right
		key 2 = Duck
		key 3 = Punch
		key 4 = Kick
		key 5 = block
		key 6 = jump
	*/
    short keys[7];
    
    SDL_Rect frames[10];
    
    gTexture image;
    
    SDL_Renderer* screen;
private:

};

#endif	/* PLAYER_HPP */

