/* 
 * File:   game.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:35 PM
 */

#include "game.hpp"

game::game() {
}

game::game(const game& orig) {
}

game::~game() {
}

bool game::init(){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS)){
        return false;
    }
    window = SDL_CreateWindow("The Co-optional Rumble", 0, 0, 1280, 720,  SDL_WINDOW_RESIZABLE );
    
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_SOFTWARE||SDL_RENDERER_PRESENTVSYNC );
    
    return true;
}

int game::run(){
    if (init() < 1){
        std::cout<<"Initiliazing failed\n";
        return 1;
    }
    
    return 0;
}