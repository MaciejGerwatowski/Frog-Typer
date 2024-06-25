#include "Text.h"
#include "fmt/core.h"
#include "Settings.h"
#include <iostream>
 std::vector<std::string> Text::wordsFromFiles =  std::vector<std::string>();
 bool Text::isLoaded = false;
Text::Text(float y) {
    if(!isLoaded) {
        loadFiles();
    }
    this->word = randomWord();
    this->y=y;

}

void Text::spawn(sf::RenderWindow& window, sf::Font& font, int wordSize) {

    // losowanie numeru z stackoverflow https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    std::random_device rd;
    std::uniform_int_distribution<int> distr(-300, -100);
    int randomX = static_cast<int>(distr(rd));
    if((-1 * randomX)%3 > 0) {
        text = sf::Text(word, font);
        text.setCharacterSize(wordSize);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Green);
        text.setPosition(randomX, y);
        //std::cout << getWord() << '\n';
    } else displaying = false;


}

void Text::spawn(sf::Font &font, float x, float y, std::string word){
    text = sf::Text(word, font);
    text.setCharacterSize(20);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Green);
    text.setPosition(x, y);
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
}

std::string Text::getWord() {
    return word;
}

std::string Text::randomWord() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, (int)wordsFromFiles.size() - 1);
    return wordsFromFiles[distr(gen)];
}

void Text::loadFiles(){
    std::vector<std::string> vec;
    auto file = std::fstream(Settings::getFile());
    auto line = std::string();

    while (std::getline(file, line)) {
        wordsFromFiles.push_back(line);
    }
    isLoaded = true;
}

bool Text::isDisplaying() const {
    return displaying;
}

void Text::setDisplaying(bool displaying) {
    Text::displaying = displaying;
}

void Text::setColor(sf::Color c) {
    text.setFillColor(c);
}

float Text::getPosition() const {
    return text.getPosition().x;
}

const sf::Text &Text::getText() const {
    return text;
}

float Text::getY() const {
    return y;
}

void Text::setWord(const std::string &word) {
    Text::word = word;
}









