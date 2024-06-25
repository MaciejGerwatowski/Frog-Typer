//          Kod pożyczony z
//https://gist.github.com/kenpower/7233967

#pragma once
#ifndef PROJEKT_FPS_H
#define PROJEKT_FPS_H


#include "SFML/System/Clock.hpp"

class FPS
{
public:
    FPS() : mFrame(0), mFps(0) {}
    const unsigned int getFPS() const { return mFps; }
    const unsigned int getMaxFPS() const { return maxFps; }

private:
    unsigned int mFrame;
    unsigned int mFps = 0;
    unsigned int maxFps;
    sf::Clock mClock;

public:
    void update()
    {
        if(mClock.getElapsedTime().asSeconds() >= 1.f)
        {
            mFps = mFrame;
            if (mFps > maxFps)
                maxFps = mFps;
            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;
    }
};


#endif //PROJEKT_FPS_H