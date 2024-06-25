#pragma once


#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

class Text : public sf::Drawable {
public:
    Text(float y);

    void spawn(sf::RenderWindow& window, sf::Font& font, int wordSize);

    std::string getWord();

    std::string randomWord();

    sf::Text text;

    bool isDisplaying() const;

    void setDisplaying(bool displaying);
    static void loadFiles();

    void setColor(sf::Color c) ;
   float getPosition() const;

    const sf::Text &getText() const;

    float getY() const;

    void setWord(const std::string &word);
    void spawn(sf::Font &font, float x, float y, std::string word);


private:
    std::string word;
    float y;
    bool displaying = true;
    static std::vector<std::string> wordsFromFiles;
    static bool isLoaded;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



