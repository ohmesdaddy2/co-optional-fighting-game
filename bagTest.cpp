/* 
 * File:   bagTest.cpp
 * Author: garys
 * 
 * Created on February 29, 2016, 1:35 PM
 */

#include "bagTest.hpp"
#include "Gevents.hpp"

bagTest::bagTest() {
    coords.x = 420;
    coords.y = 240;
    coords.w = 100;
    coords.h = 250;
}

bagTest::bagTest(const bagTest& orig) {
}

bagTest::~bagTest() {
}

int bagTest::getX(){
    return coords.x;
}

int bagTest::getY(){
    return coords.y;
}

int bagTest::getW(){
    return coords.w;
}

int bagTest::getH(){
    return coords.h;
}

bool bagTest::struck(int a, int b){
    int tempW = coords.x + coords.w;
    int tempH = coords.y + coords.h;
    
    if (a > coords.x && a < tempW && b > coords.y && b < tempH){;
        //std::cout<<"The bag has been struck\n";
        return true;
    }
    return false;
}

void bagTest::render(SDL_Renderer* screen){
    boxRGBA(screen, coords.x, coords.y, coords.x + coords.w, coords.y + coords.h, 255, 255, 0, 255);
}