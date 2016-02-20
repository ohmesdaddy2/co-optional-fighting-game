/* 
 * File:   game.hpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:35 PM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "player.hpp"
#include "fist.hpp"
#include "foot.hpp"

class game {
public:
    game();
    game(const game& orig);
    virtual ~game();
    
    bool init();
    
    int run();
    
private:
    
    SDL_Window* window;
    
    SDL_Texture* player;
    
    SDL_Renderer* screen;
    
};

#endif	/* GAME_HPP */

