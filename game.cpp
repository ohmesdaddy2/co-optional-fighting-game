/* 
 * File:   game.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:35 PM
 */

#include "game.hpp"
#include "gText.h"

game::game(){
    fontOne = NULL;
    fontTwo = NULL;
}

game::game(const game& orig){
}

game::~game(){
}

bool game::init(){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS)){
        return false;
    }
    
    window = SDL_CreateWindow("The Co-optional Rumble", 0, 0, 1280, 720,  SDL_WINDOW_RESIZABLE );
    
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_SOFTWARE||SDL_RENDERER_PRESENTVSYNC );
    
    if (TTF_Init() <0){
        std::cout<<"The text engine didn't load\n";
    }
    /*fontOne = TTF_OpenFont("Confetti-Stream.ttf", 25);
    
    if (fontOne == NULL){
        std::cout<<"The font is not loading "<<TTF_GetError()<<"\n";
        return false;
    }*/
    
    user.setup(screen, 480, 240);
    
    done = false;
    
    //scoreBoard.setup(screen, "fonts/justbeautifulsimplicity.ttf", 15, "0", 230, 50);
    
    return true;
}

void game::kickTheBag(int a, int b){
    if (hangingBag.struck(a, b) == true){
        std::cout<<"The bag has been kicked\n";
    }
    else { std::cout<<"The bag has been missed\n";
        
    }
}

void game::OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode){
    switch(unicode){
        case SDL_SCANCODE_A: user.punch(); kickTheBag(user.puncher.getFistX(), user.puncher.getFistY()); break;
        case SDL_SCANCODE_S: user.kick(); kickTheBag(user.shoe.getX(), user.shoe.getY()); break;
        case SDL_SCANCODE_ESCAPE: done = true; break;
        default: break;
    }
    
    if (unicode == SDL_SCANCODE_LEFT){
        user.moveRight = false;
        user.moveLeft = true;
    }
    if (unicode == SDL_SCANCODE_RIGHT){
        user.moveLeft = false;
        user.moveRight = true;;
        
    }
}

void game::OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode){
    user.reset();
}

void game::OnExit(){
    done = true;
}

void game::operatePlayerOne(){
    
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
        }
        
        user.stepLeft();
        user.stepRight();
        
        //SDL_RenderClear(screen);
        boxRGBA(screen, 0, 0, 1280, 720, 0, 0, 0, 255);
        
        hangingBag.render(screen);
        user.render();
        
        SDL_RenderPresent(screen);
        
        SDL_Delay(10);
    }
    IMG_Quit();
    SDL_Quit();
    return 0;
}