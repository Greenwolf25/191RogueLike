#include "Timer.h"

clock_t Timer::offset = 0;
clock_t Timer::pausedAt = 0;
bool Timer::paused = false; // true if starting game in menu


Timer::Timer()
{
    //ctor
    startAt = 0;
    startingOffset = offset;
    if(paused){
        startingOffset += clock() - pausedAt;
    }
}

Timer::~Timer()
{
    //dtor
}

void Timer::start()
{
    startingOffset = offset;
    if(paused){
        startingOffset += clock() - pausedAt;
    }
    startAt = clock();
}

void Timer::stop()
{

}

void Timer::reset()
{
    startingOffset = offset;
    if(paused){
        startingOffset += clock() - pausedAt;
    }
    startAt = clock();

}

clock_t Timer::getTicks()
{
    if(paused){
        return (clock() - startAt) - (offset - startingOffset + (clock() - pausedAt)); // if paused
    }
    return (clock() - startAt);// - (offset - startingOffset);
}

bool Timer::pause()
{
    if(paused){
        return false;
    }
    paused = true;
    cout << "paused" << endl;
    pausedAt = clock();

    return true;
}

bool Timer::unpause()
{
    if(!paused){
        return false;
    }
    cout << "unpaused" << endl;
    paused = false;
    offset += clock() - pausedAt;

    return true;
}

bool Timer::isPaused()
{
    return paused;
}

