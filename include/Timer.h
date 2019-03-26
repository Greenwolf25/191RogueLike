#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <iostream>
using namespace std;


class Timer
{
    public:
        Timer();
        virtual ~Timer();

        void start();
        void stop();
        void reset();
        static bool pause(); // return false if all ready paused
        static bool unpause();
        static bool isPaused();
        clock_t getTicks();


    protected:
        clock_t startingOffset; // total time paused from before timer creation
        static clock_t pausedAt;
        clock_t startAt;
        static clock_t offset; // total time paused

        static bool paused;
    private:
};

#endif // TIMER_H
