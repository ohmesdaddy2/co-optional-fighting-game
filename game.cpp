/* 
 * File:   game.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:35 PM
 */

#include "game.hpp"
#include "gText.h"

game::game(){
    player1Combo = 0;
    player2Combo = 0;
    playerResetTime = 0;
}

game::game(const game& orig){
}

game::~game(){
}

bool game::init(){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS)){
        return false;
    }
    
    window = SDL_CreateWindow("The Co-optional Rumble", 50, 50, 1280, 720,  SDL_WINDOW_RESIZABLE );
    
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_SOFTWARE||SDL_RENDERER_PRESENTVSYNC );
    
    if (TTF_Init() <0){
        std::cout<<"The text engine didn't load\n";
    }
    
    user[1].setup(screen, 120, 240);
	user[0].setup(screen, 600, 240);

    done = false;
    
    scoreBoard.setup(screen, "fonts/FreeMonoBold.ttf", 50, "rc", 230, 50);
    scoreBoard.setMainColor(255,255,0);
    scoreBoard.setOutlineColor(0, 255, 255);
    
    return true;
}

bool game::kickTheBag(int a, int b){
    if (hangingBag.struck(a, b) == true){
		return true;
    }
	else {
		return false;
	}
}

void game::OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode){
    switch(unicode){
        case SDL_SCANCODE_ESCAPE: done = true; break;
        default: break;
    }
    if (unicode == SDL_SCANCODE_KP_5){
        user[0].kick();
        createTheScore();
    }
    if (unicode == SDL_SCANCODE_KP_4){
        user[0].punch();
        createTheScore();
    }
    if (unicode == SDL_SCANCODE_Q){
        user[1].punch();
        createTheScore();
    }
    if (unicode == SDL_SCANCODE_E ){
        user[1].kick();
        createTheScore();
    }
    if (unicode == SDL_SCANCODE_A){
        user[1].goLeft();
    }
    if (unicode == SDL_SCANCODE_D){
        user[1].goRight();
    }
    if (unicode == SDL_SCANCODE_LEFT) {
        user[0].goLeft();
    }
    if (unicode == SDL_SCANCODE_RIGHT) {
        user[0].goRight();
    }
}

void game::OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode){
    if (unicode == SDL_SCANCODE_KP_5){
        user[0].reset();
    }
    if (unicode == SDL_SCANCODE_KP_4){
        user[0].reset();
    }
    if (unicode == SDL_SCANCODE_Q){
        user[1].reset();
    }
    if (unicode == SDL_SCANCODE_E ){
        user[1].reset();
    }
    if (unicode == SDL_SCANCODE_A){
        user[1].stop();
    }
    if (unicode == SDL_SCANCODE_D){
        user[1].stop();
    }
    if (unicode == SDL_SCANCODE_LEFT) {
        user[0].stop();
    }
    if (unicode == SDL_SCANCODE_RIGHT) {
        user[0].stop();
    }
}

void game::OnExit(){
    done = true;
}

void game::createTheScore(){
	std::stringstream tempString;
	if (kickTheBag(user[0].puncher.getFistX(), user[0].puncher.getFistY() ) == true || kickTheBag(user[0].shoe.getX(), user[0].shoe.getY() ) == true ){
            player1Combo++;
            player2Combo = 0;
	}
	else if (kickTheBag(user[1].puncher.getFistX(), user[1].puncher.getFistY() ) || kickTheBag(user[1].shoe.getX(), user[1].shoe.getY() ) == true){
            player1Combo = 0;
            player2Combo++;
	}
	
	if (player1Combo > 0) {
            tempString << player1Combo;
	}
	else if (player2Combo > 0) {
            tempString << player2Combo;
	}
    scoreBoard.update(tempString.str());
    
}

int game::run(){
    if (init()  == false){
        std::cout<<"Initiliazing failed\n";
        SDL_Quit();
        return 1;
    }
    
    while (!done){

        while (SDL_PollEvent(&inputs)){
            Gevents::OnEvent(&inputs);
        }
        user[0].operate(user[1].getX()+141, user[1].getX(), user[1].getY() );
        user[1].operate(user[0].getX()+141, user[0].getX(), user[0].getY() );
        //SDL_RenderClear(screen);
        boxRGBA(screen, 0, 0, 1280, 720, 0, 0, 0, 255);
        
        hangingBag.render(screen);
        user[0].render();
        user[1].render();
        if (player1Combo > 0 || player2Combo > 0){
                scoreBoard.render();
        }
        SDL_RenderPresent(screen);
        
        SDL_Delay(1000/60);
    }
    IMG_Quit();
    SDL_Quit();
    return 0;
}