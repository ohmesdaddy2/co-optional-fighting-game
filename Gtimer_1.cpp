/* 
 * File:   Gtimer.cpp
 * Author: garys
 * 
 * Created on October 18, 2015, 9:03 PM
 */

#include "Gtimer.hpp"

Gtimer::Gtimer() {
    second = 0;
    minute = 0;
    hour = 0;
}

Gtimer::Gtimer(const Gtimer& orig) {
}

Gtimer::~Gtimer() {
}

void Gtimer::advanceTime(){
    beginningTime = SDL_GetTicks() - globalTime;
    
    if ((beginningTime/1000) > second + (minute*60) + (hour*60) ){
        //std::cout<<"Incrementing a second\n";
        second++;
        if (second > 58){
            //std::cout<<"It has been a minute\t"<<second<<"\n";
            second = 0;
            minute++;
        }        
        if (minute > 58){
            minute = 0;
            hour++;
        }
        //std::cout<<second<<" Seconds have passed \n";
    }
}

void Gtimer::startTime(){
    globalTime = SDL_GetTicks();
    
    beginningTime = 0;
}