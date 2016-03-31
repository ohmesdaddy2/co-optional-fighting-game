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
    
    background = IMG_LoadTexture(screen, "sprites/Porch-Background.png");
    
    if (background == NULL){
        std::cout<<"The background didn't load\n";
    }
    
    backgroundCoords.x = 0;
    backgroundCoords.y = 0;
    SDL_GetWindowSize(window, &backgroundCoords.w, &backgroundCoords.h);
    
    if (TTF_Init() == -1){
        std::cout<<"The text engine didn't load"<<TTF_GetError()<<"\n";
    }
    
    user[0].setKeys(1);
    user[1].setKeys(2);
        
    user[1].setup(screen, 120, 240);
    user[0].setup(screen, 600, 240);
    
    done = false;
    
    scoreBoard.setup(screen, "fonts/FreeMono.ttf", 50, " ", 230, 50);
    scoreBoard.setMainColor(255,255,0);
    scoreBoard.setOutlineColor(0, 255, 255);
    
    return true;
}

/*bool game::kickTheBag(int a, int b){
    if (hangingBag.struck(a, b) == true){
		return true;
    }
	else {
		return false;
	}
}*/

void game::controlKeys() {
	const Uint8 *keyState = SDL_GetKeyboardState(NULL);
	
	user[0].control(keyState);
	user[1].control(keyState);

	if (keyState[SDL_SCANCODE_ESCAPE]) {
		done = true;
	}

}

void game::OnExit(){
    done = true;
}

void game::playerStrike() {
	user[0].getHit(user[1].puncher.getFistX(), user[1].puncher.getFistY());
	user[1].getHit(user[0].puncher.getFistX(), user[0].puncher.getFistY());

	user[0].getHit(user[1].shoe.getX(), user[1].shoe.getY());
	user[1].getHit(user[0].shoe.getX(), user[0].shoe.getY());
}

/*void game::createTheScore(){
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
    
}*/

void game::OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode) {
	if (sym == SDLK_ESCAPE){
		done = true;
	}
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

	controlKeys();

        user[0].operate(user[1].getX()+141, user[1].getX(), user[1].getY() );
	user[1].operate(user[0].getX() + 141, user[0].getX(), user[0].getY());
	playerStrike();
        //SDL_RenderClear(screen);
        
		//boxRGBA(screen, 0, 0, 1280, 720, 0, 0, 0, 255);
         SDL_RenderCopy(screen, background, NULL, &backgroundCoords);

        user[0].render();
        user[1].render();

        if (player1Combo > 0 || player2Combo > 0){
            scoreBoard.render();
        }

        SDL_RenderPresent(screen);
        
        SDL_Delay(1000/60);
    }
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}