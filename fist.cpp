/* 
 * File:   fist.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:37 PM
 */

#include "fist.hpp"

fist::fist() {
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

short fist::getFistY(){
    return coords.y;
}