/* 
 * File:   fist.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:37 PM
 */

#include "fist.hpp"

fist::fist() {
    coords.w = 30;
    coords.h = 30;
}

fist::fist(const fist& orig) {
}

fist::~fist() {
}

void fist::update(int a, int b){
    coords.x = a;
    coords.y = b;
}

short fist::getFistX(){
    return coords.x;
}

short fist::getFistY() {
	return coords.y;
}
    
void fist::render(SDL_Renderer* screen) {
	boxRGBA(screen, coords.x, coords.y, coords.x + coords.w, coords.y + coords.h, 255, 255, 255, 255);
}