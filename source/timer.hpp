#ifndef TIMER_HPP
#define TIMER_HPP

#include "raylib.h"

class Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)

    public:
    void startTimer(double lifetime) {
        startTime = GetTime();
        lifeTime = lifetime;
    }

    bool isDone() {
        return GetTime() - startTime >= lifeTime;
    }

    double getElapsed() {
        return GetTime() - startTime;
    }
};

#endif
