#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Event.hpp"
#include "fmt/core.h"
#include "Timer.h"
#include "GameData.h"


class Menu {
public:
    void drawMenu(sf::RenderWindow &window, sf::Font &font, GameData& data);
    bool start(sf::RenderWindow &window, bool& paused,sf::Event& event);
    void level(sf::RenderWindow &window, int& vecFrequancy, float& speed, sf::Event&);
    void startbtn(sf::RenderWindow &window, int& vecFrequancy, float& speed, bool& paused, sf::Event&, Timer& timer);
    void font(sf::RenderWindow &window,GameData& data,sf::Font& font, sf::Event&);
    void language(sf::RenderWindow &window, sf::Event&, GameData& gd);
    void exit(sf::RenderWindow &window, sf::Event&);
    const std::string &getFile() const;
    int levelPoints();

    const std::string &getCurrentFont() const;

    const std::string &getCurrentFile() const;

    const std::string &getCurrentLevel() const;

    void load(sf::RenderWindow &window, sf::Event &event, GameData &gd,sf::Font& font, bool& paused, Timer& timer, float&,int&,std::vector<Text>&);



    std::string file = "../words.txt";

private:
    bool game = false;
    std::vector<sf::Font> fonty;
    sf::Font font1;
    sf::Font font2;
    sf::Font font3;
    std::string currentLevel = "easy";
    sf::Font curFont = font1;
    sf::Color levelColor = sf::Color::Green;
    sf::Text levelTxt;
    sf::Text fontTxt;
    sf::Text fileTxt;
    sf::Texture scoreTexture;
};

