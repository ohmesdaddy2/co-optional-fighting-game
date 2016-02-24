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
    moveLeft = false;
    moveRight = false;
    faceLeft = true;
    image = passedImage;
    screen = passedScreen;
    moveSpeed = 5;
    
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
    
    frames[2].x = 565;
    frames[2].y = 0;
    frames[2].w = 282;
    frames[2].h = 356;
    
    frames[3].x = 855;
    frames[3].y = 0;
    frames[3].w = 282;
    frames[3].h = 356;
    
    frames[4].x = 1;
    frames[4].y = 357;
    frames[4].w = 282;
    frames[4].h = 356;
    
    frames[5].x = 284;
    frames[5].y = 357;
    frames[5].w = 282;
    frames[5].h = 356;
    
    frames[6].x = 568;
    frames[6].y = 357;
    frames[6].w = 282;
    frames[6].h = 356;
    
    frames[7].x = 885;
    frames[7].y = 357;
    frames[7].w = 282;
    frames[7].h = 356;
    
    state = STANCE_IDLE;
}

void player::punch(){
    if (!firstPunch){
        if (faceLeft){
        state = STANCE_LEFT_FLAT_PUNCH;
        }
        else if (!faceLeft){
            state = STANCE_OFF_LEFT_FLAT_PUNCH;
        }
        firstPunch =true;
    }
    else {
        if (faceLeft){
        state = STANCE_RIGHT_FLAT_PUNCH;
        }
        else if (!faceLeft){
            state = STANCE_OFF_RIGHT_FLAT_PUNCH;
        }
        firstPunch = false;
    }
}

void player::kick(){
    if (faceLeft){
    state = STANCE_KICK;
    }
    else if (!faceLeft){
        state = STANCE_OFF_KICK;
    }
}

void player::reset(){
    if (faceLeft){
    state = STANCE_IDLE;
    }
    else {
        state = STANCE_OFF_IDLE;
    }
    moveLeft = false;
    moveRight = false;
}

void player::stepLeft(){
    if (moveLeft){
        coords.x -= moveSpeed;
        faceLeft = true;
        state = STANCE_IDLE;
    }
}

void player::stepRight(){
    if (moveRight){
        coords.x += moveSpeed;
        faceLeft = false;
        state = STANCE_OFF_IDLE;
    }
}

void player::render(){
    switch (state){
        case STANCE_IDLE: SDL_RenderCopy(screen, image, &frames[0], &coords); break;
        case STANCE_LEFT_FLAT_PUNCH: SDL_RenderCopy(screen, image, &frames[1], &coords); break;
        case STANCE_RIGHT_FLAT_PUNCH: SDL_RenderCopy(screen, image, &frames[2], &coords); break;
        case STANCE_KICK: SDL_RenderCopy(screen, image, &frames[3], &coords); break;
        case STANCE_OFF_IDLE: SDL_RenderCopy(screen, image, &frames[4], &coords); break;
        case STANCE_OFF_LEFT_FLAT_PUNCH: SDL_RenderCopy(screen, image, &frames[5], &coords); break;
        case STANCE_OFF_RIGHT_FLAT_PUNCH: SDL_RenderCopy(screen, image, &frames[6], &coords); break;
        case STANCE_OFF_KICK: SDL_RenderCopy(screen, image, &frames[7], &coords); break;
        default: break;
    }
}
