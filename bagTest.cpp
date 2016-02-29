/* 
 * File:   bagTest.cpp
 * Author: garys
 * 
 * Created on February 29, 2016, 1:35 PM
 */

#include "bagTest.hpp"

bagTest::bagTest() {
}

bagTest::bagTest(const bagTest& orig) {
}

bagTest::~bagTest() {
}

bool bagTest::struck(int a, int b){
    if (a < coords.x + coords.w && b > coords.y && b < coords.y + coords.h){
        std::cout<<"The bag has been struck\n";
        return true;
    }
    return false;
}

void bagTest::render(SDL_Renderer* screen){
    boxRGBA(screen, coords.x, coords.y, coords.w, coords.h, 255, 255, 0, 255);
}