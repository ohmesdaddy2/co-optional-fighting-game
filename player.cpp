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

int player::getX(){
    return coords.x;
}

int player::getY(){
    return coords.y;
}

bool player::setKeys(int a) {
	playerNumber = a;
	if (playerNumber == 1) {
		keys[0] = SDL_SCANCODE_LEFT;
		keys[1] = SDL_SCANCODE_RIGHT;
		keys[2] = SDL_SCANCODE_DOWN;
		keys[3] = SDL_SCANCODE_KP_4;
		keys[4] = SDL_SCANCODE_KP_5;
		keys[5] = SDL_SCANCODE_KP_PLUS;
		keys[6] = SDL_SCANCODE_KP_0;
	}
	else if (playerNumber == 2) {
		keys[0] = SDL_SCANCODE_A;
		keys[1] = SDL_SCANCODE_D;
		keys[2] = SDL_SCANCODE_S;
		keys[3] = SDL_SCANCODE_COMMA;
		keys[4] = SDL_SCANCODE_PERIOD;
		keys[5] = SDL_SCANCODE_SLASH;
		keys[6] = SDL_SCANCODE_W;
	}
	return false;
}

bool player::getHit(int a, int b) {
	
	if ( a > hitCoords.x && a < hitCoords.w && faceLeft && !blocking) {
		std::cout << playerNumber<< "Hit from the left\n";
		//return true;
	}
	if (a < hitCoords.w && a > hitCoords.x && !faceLeft && !blocking) {
		std::cout << playerNumber<< " Hit from the right\n";
		//return true;
	}
	return false;
}

void player::setDirection(int a){
    if (coords.x + 71 > a && !faceLeft){
        faceLeft = true;
		hitCoords.x = coords.x + 154;
		hitCoords.w = hitCoords.x + 101;
    }
    else if (coords.x + coords.w - 71 < a && faceLeft){
        faceLeft = false;
		hitCoords.x = coords.x + 28;
		hitCoords.w = hitCoords.x + 101;
    }
}

bool player::setup( SDL_Renderer* passedScreen, int x, int y){
    kicking = false;
    firstPunch = false;
    moveLeft = false;
    moveRight = false;
    faceLeft = true;
    image.loadFromFile(passedScreen, "sprites/playerSprite.png", 0, 0, 0);
    screen = passedScreen;
    moveSpeed = 5;
	actionResetTime = 2;
	playerNumber = 0;
    
    coords.x = x;
    coords.y = y;
    coords.w = 282;
    coords.h = 356;
	
	hitCoords.x = coords.x + 154;
	hitCoords.y = coords.y;
	hitCoords.w = hitCoords.x + 101;
	hitCoords.h = coords.h;

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

    frames[8].x = 1445 - 282;
    frames[8].y = 0;
    frames[8].w = 282;
    frames[8].h = 356;

    frames[9].x = 1445 - 282;
    frames[9].y = 357;
    frames[9].w = 282;
    frames[9].h = 356;
    
    state = STANCE_IDLE;
	return true;
}

void player::block() {
	blocking = true;
	if (faceLeft) {
		state = STANCE_BLOCK;
	}
	else if (!faceLeft) {
		state = STANCE_OFF_BLOCK;
	}
}

void player::unBlock() {
	if (blocking) {
		blocking = false;
		if (faceLeft) {
			state = STANCE_IDLE;
		}
		else if (!faceLeft) {
			state = STANCE_OFF_IDLE;
		}
	}
}

void player::punch(){
    if (!firstPunch){
        if (faceLeft){
            state = STANCE_LEFT_FLAT_PUNCH;
            puncher.update(coords.x + 7, coords.y + 134);
        }
        else if (!faceLeft){
            state = STANCE_OFF_LEFT_FLAT_PUNCH;
			puncher.update(coords.x + 251, coords.y + 134);
        }
        firstPunch =true;
    }
    else {
        if (faceLeft){
            state = STANCE_RIGHT_FLAT_PUNCH;
            puncher.update(coords.x + 7, coords.y + 134);
        }
        else if (!faceLeft){
            state = STANCE_OFF_RIGHT_FLAT_PUNCH;
			puncher.update(coords.x + 251, coords.y + 134);
        }
        firstPunch = false;
    }
}

void player::kick(){
    if (faceLeft){
        state = STANCE_KICK;
        shoe.update(coords.x, coords.y + 185);
    }
    else if (!faceLeft){
        state = STANCE_OFF_KICK;
    }
}

void player::reset(){
	if (actionResetTime > 0) {
		actionResetTime--;
	}
	else {
		if (faceLeft) {
			state = STANCE_IDLE;
			puncher.update(coords.x + 92, coords.y + 134);
			shoe.update(coords.x + 122, coords.y + 354);
		}
		else {
			state = STANCE_OFF_IDLE;
			puncher.update(coords.x + 162, coords.y + 134);
			shoe.update(coords.x + 101, coords.y + 354);
		}
	}
}

void player::stop() {
	moveLeft = false;
	moveRight = false;
}

void player::stepLeft(){
    coords.x -= moveSpeed;
	hitCoords.x -= moveSpeed;
	hitCoords.w -= moveSpeed;
}

void player::stepRight() {
    coords.x += moveSpeed;
	hitCoords.x += moveSpeed;
	hitCoords.w += moveSpeed;
}

void player::control(const Uint8* passedKey) {

	if (passedKey[keys[0]]) {
		stepLeft();
	}
	else if (passedKey[keys[1]]) {
		stepRight();
	}
	if (passedKey[keys[2]]) {
		std::cout << "Player has ducked\n";
	}
	if (passedKey[keys[3]]) {
		punch();
		actionResetTime = 2;
	}
	if (passedKey[keys[4]]) {
		kick();
		actionResetTime = 2;
	}
	if (passedKey[keys[5]]) {
		std::cout << "Plus has been pressed\n";
		block();
	}
	else {
		unBlock();
	}

}

void player::operate(int dir, int hitA, int hitB) {
	setDirection(dir);

	if (faceLeft) {
		if (coords.x < hitA && !blocking) {
			std::cout << "Player " << playerNumber << " Has been hit\n";
		}
	}

	if (!blocking) {
		reset();
	}
}

void player::render(){
	if (playerNumber == 1) {
		boxRGBA(screen, coords.x + 120, coords.y + 160, coords.x + 180, coords.y + 190, 0, 255, 0, 255);
	}
	else if (playerNumber == 2) {
		boxRGBA(screen, coords.x + 120, coords.y + 160, coords.x + 180, coords.y + 190, 0, 0, 255, 100);
	}
    switch (state){
        case STANCE_IDLE: SDL_RenderCopy(screen, image.mTexture, &frames[0], &coords); break;
        case STANCE_LEFT_FLAT_PUNCH: SDL_RenderCopy(screen, image.mTexture, &frames[1], &coords); break;
        case STANCE_RIGHT_FLAT_PUNCH: SDL_RenderCopy(screen, image.mTexture, &frames[2], &coords); break;
        case STANCE_KICK: SDL_RenderCopy(screen, image.mTexture, &frames[3], &coords); break;
	case STANCE_BLOCK: SDL_RenderCopy(screen, image.mTexture, &frames[8], &coords); break;
        case STANCE_OFF_IDLE: SDL_RenderCopy(screen, image.mTexture, &frames[4], &coords); break;
        case STANCE_OFF_LEFT_FLAT_PUNCH: SDL_RenderCopy(screen, image.mTexture, &frames[5], &coords); break;
        case STANCE_OFF_RIGHT_FLAT_PUNCH: SDL_RenderCopy(screen, image.mTexture, &frames[6], &coords); break;
        case STANCE_OFF_KICK: SDL_RenderCopy(screen, image.mTexture, &frames[7], &coords); break;
	case STANCE_OFF_BLOCK: SDL_RenderCopy(screen, image.mTexture, &frames[9], &coords);
        default: break;
    }

}
