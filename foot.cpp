/* 
 * File:   foot.cpp
 * Author: garys
 * 
 * Created on February 16, 2016, 12:37 PM
 */

#include "foot.hpp"

foot::foot() {
    kicking = false;
}

foot::foot(const foot& orig) {
}

foot::~foot() {
}

void foot::move(int a, int b){
    coords.x = a;
    coords.y + b + 25;
    if (kicking){
        coords.x = a - 40;
        coords.y = b + 15;
    }
}
