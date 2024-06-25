#pragma once
#include <iostream>
#include <vector>
#include "Text.h"
#include "Timer.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"


class WordManager {
public:
   static std::vector<Text> tempVec(sf::RenderWindow& window, sf::Font& font, int& wordSize, int& vecFrequancy, Menu& menu);
private:
    static sf::Clock clock1;
    static bool firstSpawn;
};

