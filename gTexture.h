/* 
 * File:   gTexture.h
 * Author: garys
 *
 * Created on March 1, 2016, 3:21 PM
 */

#ifndef GTEXTURE_H
#define	GTEXTURE_H

#include <iostream>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

class gTexture {
public:
    gTexture();
    gTexture(const gTexture& orig);
    virtual ~gTexture();
    
    bool loadFromFile(SDL_Renderer* a, std::string path, Uint8 removedRed, Uint8 removedGreen, Uint8 removedBlue);
    
    void free();
    
    void render( int x, int y);
    
    int getWidth();
    int getHeight();
    
    SDL_Texture* mTexture;
private:
    
    SDL_Renderer* mainScreen;
    
    int mWidth;
    int mHeight;

};

#endif	/* GTEXTURE_H */

