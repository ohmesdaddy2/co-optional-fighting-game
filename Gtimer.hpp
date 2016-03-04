/* 
 * File:   Gtimer.hpp
 * Author: garys
 *
 * Created on October 18, 2015, 9:03 PM
 */

#ifndef GTIMER_HPP
#define	GTIMER_HPP

#include "SDL2/SDL.h"
#include <iostream>
class Gtimer {
public:
    Gtimer();
    Gtimer(const Gtimer& orig);
    virtual ~Gtimer();
    
    Uint32 globalTime;
    
    Uint32 beginningTime;
    
    Uint32 second;
    
    Uint32 minute;
    
    Uint16 hour;
    
    void advanceTime();
    
    void startTime();
    
private:
    
};

#endif	/* GTIMER_HPP */

