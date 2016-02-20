/* 
 * File:   player.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:37 PM
 */

#include "player.hpp"

player::player() {
}

player::player(const player& orig) {
}

player::~player() {
}

bool player::setup(SDL_Texture* passedImage, SDL_Renderer* passedScreen, int x, int y){
    kicking = false;
    firstPunch = false;
    image = passedImage;
    screen = passedScreen;
    
    coords.x = x;
    coords.y = y;
    coords.w = 282;
    coords.h = 356;
    
    frames[0].x = 0;
    frames[0].y = 0;
    frames[0].w = 282;
    frames[0].h = 356;
    
    frames[1].x = 284;
    frames[1].y = 0;
    frames[1].w = 282;
    frames[1].h = 356;
    
    frames[2].x = 566;
    frames[2].y = 0;
    frames[2].w = 282;
    frames[2].h = 356;
    
    frames[3].x = 846;
    frames[3].y = 0;
    frames[3].w = 282;
    frames[3].h = 356;
    
    state = STANCE_IDLE;
}

void player::punch(){
    state = STANCE_LEFT_FLAT_PUNCH;
}

void player::kick(){
    state = STANCE_KICK;
}

void player::reset(){
    state = STANCE_IDLE;
}

void player::moveLeft(){
    std::cout<<"The left moving event\n";
}

void player::moveRight(){
    std::cout<<"The right moving event\n";
}

void player::render(){
    switch (state){
        case STANCE_IDLE: SDL_RenderCopy(screen, image, &frames[0], &coords); break;
        case STANCE_LEFT_FLAT_PUNCH: SDL_RenderCopy(screen, image, &frames[1], &coords); break;
        case STANCE_KICK: SDL_RenderCopy(screen, image, &frames[3], &coords); break;;
    }
}
