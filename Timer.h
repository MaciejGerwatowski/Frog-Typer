#pragma once

#include "SFML/System/Clock.hpp"
#include <string>
#include <iostream>

class Timer {
private:
    sf::Time startTime;
    sf::Clock timer;
    sf::Time currentTime;
    bool isRunning;
    void pause();


public:
    Timer();
    void update(bool paused);
    std::string getTimeAsString() const;
    void start();
    void restart();

    void setIsRunning(bool isRunning);

    const sf::Time &getCurrentTime() const;

    void setCurrentTime(const float time);


};



