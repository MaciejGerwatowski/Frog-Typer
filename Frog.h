#pragma once

#include <iostream>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <SFML/Graphics.hpp>

class Frog {
public:
    static sf::Sprite frogSpawn();
    static void frogUpdate(int &missedWords, sf::RenderWindow& window);

private:
   static sf::Texture frogTexture;
};


