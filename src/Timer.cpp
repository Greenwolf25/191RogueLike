#include "Timer.h"

clock_t Timer::offset = 0; // start total time paused at 0
clock_t Timer::pausedAt = 0;
bool Timer::paused = true; // true if starting game in menu


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
    startingOffset = offset; // starting offset is total time pause when the timer was created
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
    startingOffset = offset; // same as start()
    if(paused){
        startingOffset += clock() - pausedAt;
    }
    startAt = clock();

}

clock_t Timer::getTicks()
{
    if(paused){
        return (clock() - startAt) - (offset - startingOffset + (clock() - pausedAt)); // if paused
        // returns the clock ticks since the clock was started/reset minus the amount of time pause and the current amount of time pause
    }
    return (clock() - startAt) - (offset - startingOffset);
    //returns the clock ticks since the clock was started/reset minus the amount of time pause
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
    offset += clock() - pausedAt; // adds pause time to total time paused

    return true;
}

bool Timer::isPaused()
{
    return paused;
}

