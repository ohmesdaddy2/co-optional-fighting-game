/*
 * File:   Gevents.hpp
 * Author: garys
 *
 * Created on January 3, 2014, 7:52 PM
 */

#ifndef GEVENTS_HPP
#define	GEVENTS_HPP

#include "SDL2/SDL.h"

class Gevents {
public:
    Gevents();

    void OnEvent(SDL_Event* Event);

    virtual void OnInputFocus();

    virtual void OnInputBlur();

    virtual void OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode);

    virtual void OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode);

    virtual void OnMouseFocus();

    virtual void OnMouseBlur();

    virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

    virtual void OnMouseWheel(bool Up, bool Down);    //Not implemented

    virtual int OnLButtonDown(int mX, int mY);
    
    virtual void OnLButtonDown(int mX, int mY, Uint32 mod);

    virtual void OnLButtonUp(int mX, int mY);

    virtual void OnRButtonDown(int mX, int mY);

    virtual void OnRButtonUp(int mX, int mY);

    virtual void OnMButtonDown(int mX, int mY);

    virtual void OnMButtonUp(int mX, int mY);

    virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

    virtual void OnJoyButtonDown(Uint8 which, Uint8 button);

    virtual void OnJoyButtonUp(Uint8 which, Uint8 button);

    virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);

    virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);

    virtual void OnMinimize();

    virtual void OnRestore();

    virtual void OnResize(int w,int h);

    virtual void OnExpose();

    virtual void OnExit();

    virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};

#endif	/* GEVENTS_HPP */

