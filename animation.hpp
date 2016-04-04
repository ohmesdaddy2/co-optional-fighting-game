/* 
 * File:   animation.hpp
 * Author: garys
 *
 * Created on April 3, 2016, 12:13 PM
 */

#ifndef ANIMATION_HPP
#define	ANIMATION_HPP

#include "SDL2/SDL.h"
#include <boost/ptr_container/ptr_vector.hpp>

class animation {
public:
    
    SDL_Rect currentFrame;
    
    void setFrameCount(int a);
    
    /*Set the width and height of each frame based off the source sprite
     *!!!EACH FRAME MUST BE THE SAME DIMENSIONS!!!!
     */
    void setFrameSize(int sourceWidth, int sourceHeight);
    
    /*Set where the animation begins on the sprite sheet.
     * each frame must be on the same Y coordinate for the full duration
     */
    void setFrameStart(int startX, int startY);
    
    /*Send the sprites for the animations into the class*/
    void passSpriteSheet(std::string filePash);
    
    animation();
    animation(const animation& orig);
    virtual ~animation();
private:
    
    SDL_Texture* sprite;
    
    boost::ptr_vector<SDL_Rect> frames;

};

#endif	/* ANIMATION_HPP */

