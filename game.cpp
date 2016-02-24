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
    
    playerSprite = IMG_LoadTexture(screen,"sprites/playerSprite.png");;
    user.setup(playerSprite, screen, 480, 240);
    
    done = false;
    
    return true;
}

void game::OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode){
    switch(sym){
        case SDLK_a: user.punch(); break;
        case SDLK_s: user.kick(); break;
        default: break;
    }
    
    if (sym == SDLK_LEFT){
        user.moveRight = false;
        user.moveLeft = true;
    }
    if (sym == SDLK_RIGHT){
        user.moveLeft = false;
        user.moveRight = true;;
        
    }
}

void game::OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode){
    user.reset();
}

int game::run(){
    if (init() < 1){
        std::cout<<"Initiliazing failed\n";
        SDL_Quit();
        return 1;
    }
    
    while (!done){
        while (SDL_PollEvent(&inputs)){
            Gevents::OnEvent(&inputs);
            if (inputs.type == SDL_QUIT){
                done = true;
            }
        }
        
        user.stepLeft();
        user.stepRight();
        
        SDL_RenderClear(screen);
        
        user.render();
        
        SDL_RenderPresent(screen);
        
        SDL_Delay(10);
    }
    SDL_Quit();
    return 0;
}