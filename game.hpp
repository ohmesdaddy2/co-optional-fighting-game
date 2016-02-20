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

#include "player.hpp"
#include "fist.hpp"
#include "foot.hpp"
#include "Gevents.hpp"

class game:public Gevents {
public:
    game();
    game(const game& orig);
    virtual ~game();
    
    bool init();
    
    int run();
    
private:
    
    void OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode);
    
    void OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode);
    
    bool done;
    
    SDL_Event inputs;
    
    SDL_Window* window;
    
    SDL_Texture* playerSprite;
    
    SDL_Renderer* screen;
    
    player user;
};

#endif	/* GAME_HPP */

