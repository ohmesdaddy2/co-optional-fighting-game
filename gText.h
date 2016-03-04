/* 
 * File:   gText.h
 * Author: garys
 *
 * Created on March 2, 2016, 11:33 AM
 */

#ifndef GTEXT_H
#define	GTEXT_H

#include <string>
#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

class gText {
public:
    gText();
    gText(const gText& orig);
    virtual ~gText();
    
    void setMainColor(Uint8 red, Uint8 green, Uint8 blue);
    
    void setOutlineColor(Uint8 red, Uint8 green, Uint8 blue);
    
    bool setup(SDL_Renderer* a, std::string fontPath, int fontSize, std::string passedText, int passedX, int passedY);
    
    void render();
    
private:
    
    std::string text;
    
    TTF_Font* mainFont;
    
    TTF_Font* outlineFont;
    
    SDL_Color mainColor;
    
    SDL_Color outlineColor;
    
    SDL_Texture* mainTexture;
    
    SDL_Texture* outlineTexture;
    
    SDL_Renderer* mainScreen;
    
    SDL_Rect coords;

};

#endif	/* GTEXT_H */

