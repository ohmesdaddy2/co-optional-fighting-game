/* 
 * File:   lifeTracker.cpp
 * Author: garys
 * 
 * Created on March 28, 2016, 10:38 AM
 */

#include "lifeTracker.hpp"

lifeTracker::lifeTracker() {
}

lifeTracker::lifeTracker(const lifeTracker& orig) {
}

lifeTracker::~lifeTracker() {
}

void lifeTracker::place(int a, int b){
    coords.x = a;
    coords.y = b;
    coords.w = a + 100;
    coords.h = b + 20;
    color.r = 0;
    color.g = 255;
    color.b = 0;
    color.a = 255;
}

void lifeTracker::reduce(int damage){
    amount -= damage;
}

void lifeTracker::render(SDL_Renderer* screen){
    boxRGBA(screen, coords.x, coords.y, coords.w, coords.h, color.r, color.g, color.b, color.a);;
}