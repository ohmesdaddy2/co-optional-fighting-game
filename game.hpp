/* 
 * File:   game.hpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:35 PM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "gTexture.h"
#include "gText.h"
#include "player.hpp"
#include "fist.hpp"
#include "foot.hpp"
#include "Gevents.hpp"

#include "bagTest.hpp"

class game:public Gevents{

private:
    
    void OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode);
    
    void OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode);
    
    void OnExit();
    
    void operatePlayerOne();
    
    bool done;
    
    int player1Combo;
    
    int player2Combo;
    
    SDL_Event inputs;
    
    TTF_Font* fontOne;
    TTF_Font* fontTwo;
    
    SDL_Window* window;
    
    gTexture playerSprite;
    gText scoreBoard;
    
    SDL_Renderer* screen;
    
    player user;
    
    bagTest hangingBag;
    
public:
    game();
    game(const game& orig);
    virtual ~game();
    
    bool init();
    
    void kickTheBag(int a, int b);
    
    int run();
    
};

#endif	/* GAME_HPP */

