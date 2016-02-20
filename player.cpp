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
    coords.w = 105;
    coords.h = 183;
    
    frames[0].x = 33;
    frames[0].y = 3;
    frames[0].w = 188;
    frames[0].h = 353;
    
    frames[1].x = 247;
    frames[1].y = 5;
    frames[1].w = 278;
    frames[1].h = 353;
    
    frames[2].x = 545;
    frames[2].y = 4;
    frames[2].w = 255;
    frames[2].h = 349;
    
    frames[3].x = 40;
    frames[3].y = 420;
    frames[3].w = 292;
    frames[3].h = 351;
    
    state = STANCE_IDLE;
}

void player::punch(){
    state = STANCE_LEFT_FLAT_PUNCH;
}

void player::kick(){
    state = STANCE_KICK;
}

void player::moveLeft(){
    std::cout<<"The left moving event\n";
}

void player::moveRight(){
    
}

void player::render(){
    
}
