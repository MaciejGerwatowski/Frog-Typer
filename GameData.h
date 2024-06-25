#pragma once

#include <iostream>
#include <fstream>
#include "SFML/Graphics/Text.hpp"
#include "Text.h"
#include "Timer.h"

class GameData {
public:
    void saveGameState(std::vector<Text>& words, int score, int missed, int typped, std::string  level, Timer timer);
    void loadGameState(sf::Font &font,std::vector<Text>&);

    int getWordSize() const;

    void setWordSize(int wordSize);

    float getSpeed() const;

    void setSpeed(float speed);

    int getNewVectorFrequency() const;

    void setNewVectorFrequency(int newVectorFrequency);

    bool isPaused() const;

    void setPaused(bool paused);

    int getMissedWords() const;

    void setMissedWords(int missedWords);

    int getTyppedWords() const;

    void setTyppedWords(int typpedWords);

    int getScore() const;

    void setScore(int score);

    float getTime() const;

    const std::vector<Text> &getCurrentWords() const;

    const std::string &getCurrentLevel() const;

    const std::string &getCurrentFont() const;

    void setCurrentFont(const std::string &currentFont);

    const std::string &getCurrentFile() const;

    void setCurrentFile(const std::string &currentFile);


private:
    std::vector<Text> currentWords;
    bool isDisplaying;

    int wordSize = 20;
    float speed = 1.f;
    int newVectorFrequency = 10;
    bool paused = true;
    int missedWords = 0;
    int typpedWords = 0;
    int score = 0;
    float time = 0;
    std::string currentLevel;
    std::string currentFont = "Font1";
    std::string currentFile = "english";
};


