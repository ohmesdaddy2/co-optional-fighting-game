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
    coords.w = coords.x + 100;
    coords.h = coords.y + 20;
    color.r = 0;
    color.g = 255;
    color.b = 0;
    color.a = 255;
    amount = 100;
}

void lifeTracker::reduce(int damage){
    if (amount > 0){
        amount -= damage;
    }
}

void lifeTracker::render(SDL_Renderer* screen){
    boxRGBA(screen, coords.x, coords.y, coords.w, coords.h, 255, 0, 0, 255);
    boxRGBA(screen, coords.w - amount, coords.y, coords.w, coords.h, color.r, color.g, color.b, color.a);
}