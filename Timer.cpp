
#include "Timer.h"

void Timer::update(bool paused) {
    if (isRunning) {
        if (paused) {
            timer.restart();
        } else {
            currentTime += timer.restart();
        }
    }
}

std::string Timer::getTimeAsString() const {
    sf::Time totalTime = currentTime;
    int minutes = (int) (totalTime.asSeconds() / 60) % 60;
    int seconds = (int) totalTime.asSeconds() % 60;

    std::string timeString;
    timeString += (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":";
    timeString += (seconds < 10 ? "0" : "") + std::to_string(seconds);
    return timeString;
}

void Timer::start() {
    isRunning = true;
}

Timer::Timer() {
    sf::Clock clock2;
    isRunning = false;
    currentTime = sf::Time::Zero;
}

void Timer::pause() {
    setIsRunning((!isRunning));
}

void Timer::setIsRunning(bool isRunning) {
    Timer::isRunning = isRunning;
}

void Timer::restart() {
    timer.restart();
}

const sf::Time &Timer::getCurrentTime() const {
    return currentTime;
}

void Timer::setCurrentTime(const float time) {
    Timer::currentTime = sf::seconds(time);
}


