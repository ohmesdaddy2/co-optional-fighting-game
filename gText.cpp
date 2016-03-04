/* 
 * File:   gText.cpp
 * Author: garys
 * 
 * Created on March 2, 2016, 11:33 AM
 */

#include "gText.h"

gText::gText() {
    text = "";
    mainFont = NULL;
    outlineFont = NULL;
    mainTexture = NULL;
    outlineTexture = NULL;
    mainScreen = NULL;
    coords.x = -500;
    coords.y = -500;
    coords.w = 0;
    coords.h = 0;
    
    mainColor.r = 128;
    mainColor.g = 128;
    mainColor.b = 128;
    
    outlineColor.r = 255;
    outlineColor.g = 255;
    outlineColor.b = 255;
}

gText::gText(const gText& orig) {
}

gText::~gText() {
}

void gText::setMainColor(Uint8 red, Uint8 green, Uint8 blue){
    mainColor.r = red;
    mainColor.g = green;
    mainColor.b = blue;
}

void gText::setOutlineColor(Uint8 red, Uint8 green, Uint8 blue){
    outlineColor.r = red;
    outlineColor.g = green;
    outlineColor.b = blue;;
}

bool gText::setup(SDL_Renderer* a, std::string fontPath, int fontSize, std::string passedText, int passedX, int passedY){
    text = passedText;
    mainScreen = a;
    coords.x = passedX;
    coords.y = passedY;
    
    mainFont = TTF_OpenFont(fontPath.c_str(), fontSize);
    
    if (mainFont == NULL){
        std::cout<<"The font didn't load\n";
    }
    
    outlineFont = TTF_OpenFont(fontPath.c_str(), fontSize);
    
    if (outlineFont == NULL){
        std::cout<<"The outline font didn't load\n";
    }
    
    TTF_SetFontOutline(outlineFont, 5);
    
    SDL_Surface* tempSurface = TTF_RenderText_Solid(mainFont, text.c_str(), mainColor);
    SDL_Surface* tempOutlineSurface = TTF_RenderText_Solid(outlineFont, text.c_str(), outlineColor);
    
    mainTexture = SDL_CreateTextureFromSurface(mainScreen, tempSurface);
    if (mainTexture == NULL){
        std::cout<<"Unable to create the texture "+text+" \n";
        return false;
    }
    
    outlineTexture = SDL_CreateTextureFromSurface(mainScreen, tempOutlineSurface);
    if (outlineTexture == NULL){
        std::cout<<"Unable to create the outline "+text+" \n";
        return false;
    }
    
    coords.w = tempSurface->w;
    coords.h = tempSurface->h;
    
    return true;
}

void gText::render(){
    SDL_RenderCopy(mainScreen, mainTexture, NULL, &coords);
    SDL_RenderCopy(mainScreen, outlineTexture, NULL, &coords);
}