/* 
 * File:   game.hpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:35 PM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#define DEBUG_RENDER

#include <iostream>
#include <string>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "gTexture.h"
#include "gText.h"
#include "player.hpp"
#include "fist.hpp"
#include "foot.hpp"
#include "Gevents.hpp"
#include "Gtimer.hpp"

#include "bagTest.hpp"

class game:public Gevents{

private:
    
    void OnExit();

	void OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode);
    
    //void createTheScore();

	void controlKeys();

	void playerStrike();
    
    void cleanUp();
    
    bool done;
    
    int player1Combo;
    
    int player2Combo;
    
	short playerResetTime;

    SDL_Event inputs;
    
    SDL_Window* window;
    
    gTexture playerSprite;
    gText scoreBoard;
    
    SDL_Texture* background;
    
    SDL_Rect backgroundCoords;
    
    SDL_Renderer* screen;
    
    player user[2];
    
    Gtimer clock;
    
    short loopCount;
    
    Uint16 gameSec;
    
    //bagTest hangingBag;
    
public:
    game();
    game(const game& orig);
    virtual ~game();
    
    bool init();
    
    //bool kickTheBag(int a, int b);
    
    int run();
    
};

#endif	/* GAME_HPP */

