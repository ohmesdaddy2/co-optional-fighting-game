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
		case SDL_SCANCODE_Q: user[1].punch(); createTheScore(); break;
		case SDL_SCANCODE_E: user[1].kick(); createTheScore(); break;
		case SDL_SCANCODE_KP_4: user[0].punch(); createTheScore(); break;
		case SDL_SCANCODE_KP_5: user[0].kick(); createTheScore(); break;
        case SDL_SCANCODE_ESCAPE: done = true; break;
        default: break;
    }
    
    if (unicode == SDL_SCANCODE_A){
        user[1].moveRight = false;
        user[1].moveLeft = true;
    }
    if (unicode == SDL_SCANCODE_D){
        user[1].moveLeft = false;
        user[1].moveRight = true;
    }
	if (unicode == SDL_SCANCODE_LEFT) {
		user[0].moveRight = false;
		user[0].moveLeft = true;
	}
	if (unicode == SDL_SCANCODE_RIGHT) {
		user[0].moveRight = true;
		user[0].moveLeft = false;
	}
}

void game::OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode){
	switch (unicode) {
	case SDL_SCANCODE_LEFT: user[0].stop(); break;
	case SDL_SCANCODE_RIGHT: user[0].stop(); break;
	case SDL_SCANCODE_A: user[1].stop(); break;
	case SDL_SCANCODE_D: user[1].stop(); break;
	case SDL_SCANCODE_Q: user[1].reset(); break;
	case SDL_SCANCODE_E: user[1].reset(); break;
	case SDL_SCANCODE_KP_4: user[0].reset(); break;
	case SDL_SCANCODE_KP_5: user[0].reset(); break;
	default: break;
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
        
        user[0].stepLeft();
        user[0].stepRight();

		user[1].stepLeft();
		user[1].stepRight();

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