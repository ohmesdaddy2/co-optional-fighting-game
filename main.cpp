/* 
 * File:   main.cpp
 * Author: garys
 *
 * Created on February 16, 2016, 12:34 PM
 */

#include <cstdlib>

#include "game.hpp"

#define DEBUG_RENDER

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    game world;
    
    return world.run();
}

