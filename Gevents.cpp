/* 
 * File:   Gevents.cpp
 * Author: garys
 * 
 * Created on January 3, 2014, 7:52 PM
 */

#include "Gevents.hpp"

Gevents::Gevents() {
}

void Gevents::OnEvent(SDL_Event* Event) {
    switch(Event->type) {
 
        case SDL_KEYDOWN: {
            OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
            break;
        }
 
        case SDL_KEYUP: {
            OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
            break;
        }
 
        case SDL_MOUSEMOTION: {
            OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }
 
        case SDL_MOUSEBUTTONDOWN: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonDown(Event->button.x,Event->button.y);
                    OnLButtonDown(Event->button.x, Event->button.y, Event->key.keysym.mod);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonDown(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonDown(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }
 
        case SDL_MOUSEBUTTONUP:    {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }
 
        case SDL_JOYAXISMOTION: {
            OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
            break;
        }
 
        case SDL_JOYBALLMOTION: {
            OnJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
            break;
        }
 
        case SDL_JOYHATMOTION: {
            OnJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            OnJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
            break;
        }
 
        case SDL_JOYBUTTONUP: {
            OnJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
            break;
        }
 
        case SDL_QUIT: {
            OnExit();
            break;
        }
 
        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }
        
        default: {
            OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
            break;
        }
    }
}
 
void Gevents::OnInputFocus() {
    //Pure virtual, do nothing
}
 
void Gevents::OnInputBlur() {
    //Pure virtual, do nothing
}
 
void Gevents::OnKeyDown(Uint32 sym, Uint32 mod, Uint16 unicode) {
    //Pure virtual, do nothing
}
 
void Gevents::OnKeyUp(Uint32 sym, Uint32 mod, Uint16 unicode) {
    //Pure virtual, do nothing
}
 
void Gevents::OnMouseFocus() {
    //Pure virtual, do nothing
}
 
void Gevents::OnMouseBlur() {
    //Pure virtual, do nothing
}
 
void Gevents::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    //Pure virtual, do nothing
}
 
void Gevents::OnMouseWheel(bool Up, bool Down) {
    //Pure virtual, do nothing
}
 
int Gevents::OnLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
	return 0;
}
 
void Gevents::OnLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void Gevents::OnLButtonDown(int mX, int mY, Uint32 mod){
    //Pure virtual, do nothing
}
 
void Gevents::OnRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}
 
void Gevents::OnRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}
 
void Gevents::OnMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}
 
void Gevents::OnMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}
 
void Gevents::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    //Pure virtual, do nothing
}
 
void Gevents::OnJoyButtonDown(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}
 
void Gevents::OnJoyButtonUp(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}
 
void Gevents::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
    //Pure virtual, do nothing
}
 
void Gevents::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    //Pure virtual, do nothing
}
 
void Gevents::OnMinimize() {
    //Pure virtual, do nothing
}
 
void Gevents::OnRestore() {
    //Pure virtual, do nothing
}
 
void Gevents::OnResize(int w,int h) {
    //Pure virtual, do nothing
}
 
void Gevents::OnExpose() {
    //Pure virtual, do nothing
}
 
void Gevents::OnExit() {
    //Pure virtual, do nothing
}
 
void Gevents::OnUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}