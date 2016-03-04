/* 
 * File:   foot.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:37 PM
 */

#include "foot.hpp"

foot::foot() {
    kicking = false;
    coords.w = 59;
    coords.h = 48;
    
}

foot::foot(const foot& orig) {
}

foot::~foot() {
}

void foot::update(int a, int b){
    coords.x = a;
    coords.y = b;
}

int foot::getX(){
    return coords.x;
}

int foot::getY(){
    return coords.y;
}
