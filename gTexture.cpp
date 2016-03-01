/* 
 * File:   gTexture.cpp
 * Author: garys
 * 
 * Created on March 1, 2016, 3:21 PM
 */

#include "gTexture.h"

gTexture::gTexture() {
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

gTexture::gTexture(const gTexture& orig) {
}

gTexture::~gTexture() {
    free();
}

bool gTexture::loadFromFile(SDL_Renderer* a, std::string path, Uint8 removedRed, Uint8 removedGreen, Uint8 removedBlue){
    SDL_Texture* newTexture = NULL;
    mainScreen = a;
    //Load the texture from the file
    SDL_Surface* loadedSurface(IMG_Load(path.c_str()));
    if (loadedSurface ==NULL){
        printf("Unable to load image %s! SDL_image Errer: %s\n", path.c_str(), IMG_GetError() );
    }
    else {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, removedRed, removedGreen, removedBlue));
        
        newTexture = SDL_CreateTextureFromSurface(mainScreen, loadedSurface);
        if (newTexture==NULL){
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else{
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    mTexture = newTexture;
    return mTexture != NULL;
}

void gTexture::free(){
    if(mTexture != NULL){
        SDL_DestroyTexture(mTexture);
        mWidth = 0;
        mHeight = 0;
    }
}

void gTexture::render(int x, int y){
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopy(mainScreen, mTexture, NULL, &renderQuad);
}

int gTexture::getWidth(){
    return mWidth;
}

int gTexture::getHeight(){
    return mHeight;
}