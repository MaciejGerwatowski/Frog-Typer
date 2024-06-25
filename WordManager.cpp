
#include "WordManager.h"

sf::Clock WordManager::clock1;
bool WordManager::firstSpawn = true;


std::vector<Text> WordManager::tempVec(sf::RenderWindow& window, sf::Font& font, int& wordSize, int& vecFrequancy, Menu& menu) {
        std::vector<Text> wordsTemp;

        if(firstSpawn){
            wordsTemp.clear();

            auto s1 = Text(200);
            s1.spawn(window, font, wordSize);
            auto s2 = Text(300);
            s2.spawn(window, font, wordSize);

            auto s3 = Text(400);
            s3.spawn(window, font, wordSize);
            auto s4 = Text(500);
            s4.spawn(window, font, wordSize);

            auto s5 = Text(600);
            s5.spawn(window, font, wordSize);
            auto s6 = Text(700);
            s6.spawn(window, font, wordSize);

            if (s1.isDisplaying()) wordsTemp.push_back(s1);
            if (s2.isDisplaying()) wordsTemp.push_back(s2);
            if (s3.isDisplaying()) wordsTemp.push_back(s3);
            if (s4.isDisplaying()) wordsTemp.push_back(s4);
            if (s5.isDisplaying()) wordsTemp.push_back(s5);
            if (s6.isDisplaying()) wordsTemp.push_back(s6);
            firstSpawn = false;
        }



    if (clock1.getElapsedTime().asSeconds() > vecFrequancy) {
        clock1.restart();
        wordsTemp.clear();

        auto s1 = Text(200);
        s1.spawn(window, font, wordSize);
        auto s2 = Text(300);
        s2.spawn(window, font, wordSize);

        auto s3 = Text(400);
        s3.spawn(window, font, wordSize);
        auto s4 = Text(500);
        s4.spawn(window, font, wordSize);

        auto s5 = Text(600);
        s5.spawn(window, font, wordSize);
        auto s6 = Text(700);
        s6.spawn(window, font, wordSize);

        if (s1.isDisplaying()) wordsTemp.push_back(s1);
        if (s2.isDisplaying()) wordsTemp.push_back(s2);
        if (s3.isDisplaying()) wordsTemp.push_back(s3);
        if (s4.isDisplaying()) wordsTemp.push_back(s4);
        if (s5.isDisplaying()) wordsTemp.push_back(s5);
        if (s6.isDisplaying()) wordsTemp.push_back(s6);
    }
    return wordsTemp;
}
