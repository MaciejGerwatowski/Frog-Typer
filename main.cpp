#include <SFML/Graphics.hpp>
#include <iostream>
#include <fmt/core.h>
#include <fstream>
#include <fmt/ranges.h>
#include <deque>
#include "Text.h"
#include "Timer.h"
#include "WordManager.h"
#include "Frog.h"
#include "FPS.h"
#include "Menu.h"
#include "GameData.h"
#include "Settings.h"

auto operator+=(std::vector<Text> &vec1, std::vector<Text> vec2) -> std::vector<Text> {

    for (auto &i: vec2) {
        vec1.push_back(i);
    }
    return vec1;
}

void drawMainMenu(sf::RenderWindow &window, sf::Font &font) {
    auto menuTexture = sf::Texture();
    if (!menuTexture.loadFromFile("../assets/menu-1.jpg")) std::cout << "can not load image \n";
    auto menuView = sf::Sprite(menuTexture);
    menuView.setScale(0.75, 0.75);
    window.draw(menuView);
}

int bestScore = 0;
void displayBestScore(sf::Font font, sf::RenderWindow& window){
    const char* filename = "../assets/best_score.txt";
    std::fstream file;
    file.open(filename, std::ios::in);
    if (file.is_open()) {
        file >> bestScore;
        file.close();
    }
    auto bestScoreD = sf::Text(std::to_string(bestScore), font);
    bestScoreD.setPosition(105, 145);
    bestScoreD.setFillColor(sf::Color::Yellow);
    window.draw(bestScoreD);
}


void saveBestScore(int currentScore) {
    const char* filename = "../assets/best_score.txt";
    std::fstream file;
    file.open(filename, std::ios::in);
    if (file.is_open()) {
        file >> bestScore;
        file.close();
    }
    if (currentScore > bestScore) {
        file.open(filename, std::ios::out | std::ios::trunc);
        if (file.is_open()) {
            file << currentScore;
            //std::cout << "Nowy najlepszy wynik: " << currentScore << std::endl;
        } else {
            std::cout << "can not load file" << std::endl;
        }
        file.close();
    } else {
       // std::cout << "Aktualny wynik (" << currentScore << ") groszy od najlepszego wyniku (" << bestScore << ")." << std::endl;
    }
}

auto main() -> int {

    auto window = sf::RenderWindow(
            sf::VideoMode({1344, 756}), "Frog Typer", sf::Style::Close, sf::ContextSettings(0, 0, 8)
    );
    window.setFramerateLimit(60);

    Settings settings;

    auto texture = sf::Texture();
    if (!texture.loadFromFile("../assets/background7.jpg")) std::cout << "can not load image \n";

    auto background = sf::Sprite(texture);
    background.setScale(0.8, 0.8);


    auto debugInput = std::string();
    auto game = false;
    auto menu = true;

    auto frog = Frog::frogSpawn();
    // czcionka
    sf::Font font;
    font.loadFromFile("../assets/Roboto-Medium.ttf");

    //zegary
    sf::Clock clock_cursor;
    sf::Clock clock1;
    Timer timer;
    sf::Text timerText("", font, 24);
    timerText.setPosition(window.getSize().x - 200, 10);

    //countery
    GameData gd;
    std::vector<Text> words = gd.getCurrentWords();


    auto wordSize = gd.getWordSize();
    float speed = gd.getSpeed();
    auto newVectorFrequency = gd.getNewVectorFrequency();
    auto paused = true;
    auto missedWords = gd.getMissedWords();
    auto typpedWords = gd.getTyppedWords();
    auto score = gd.getScore();

    auto missedCounter = sf::Text("missed: " + std::to_string(missedWords), font);
    auto typpedCounter = sf::Text("typped: " + std::to_string(typpedWords), font);
    auto scoreCounter = sf::Text("Score: " + std::to_string(score), font );
    missedCounter.setPosition(window.getSize().x - 200, 100);
    typpedCounter.setPosition(window.getSize().x - 200, 50);
    scoreCounter.setPosition(window.getSize().x - 400, 50);
    sf::Text textBox("", font);




    //menu
    Menu mainMenu;


    bool end = false;
    while (window.isOpen()) {

        auto event = sf::Event();

        while (window.pollEvent(event) ) {
            if (event.type == sf::Event::TextEntered && !paused) {
                auto enteredWord = (char) (event.text.unicode);

                // sprawdzanie czy da sie wydrukowac
                if (enteredWord >= 32 && enteredWord < 127) {
                }

                if (event.text.unicode == 10) {

                    for (auto &t: words) {
                        if (debugInput == t.getWord()) {
                            typpedWords++;
                            gd.setTyppedWords(gd.getTyppedWords() + 1);
                            gd.setScore(gd.getScore() + mainMenu.levelPoints());
                            typpedCounter.setString("typped: " + std::to_string(typpedWords));
                            scoreCounter.setString("Score: " + std::to_string(score));
                            t.setDisplaying(false);
                        }
                    }

                    debugInput.clear();
                } else if (event.text.unicode == 8) { // Obsługa backspace
                    if (!debugInput.empty()) {
                        debugInput.pop_back();
                    }
                } else if (debugInput.size() < 25) {
                    debugInput += enteredWord;
                }
            }


            //---- skroty klawiszowe ----
            if (event.type == sf::Event::KeyPressed && !paused) {
                if (event.key.code == sf::Keyboard::Up && wordSize <= 40) {
                    wordSize += 3;

                }
                if (event.key.code == sf::Keyboard::Down && wordSize >= 15) {
                    wordSize -= 3;
                }
                //do debug
                if (event.key.code == sf::Keyboard::Right) {
                    for (auto i: words) {
                        fmt::print("{} ", i.getWord());
                    }
                }
            }

                if (event.type == sf::Event::Closed) {
                    saveBestScore(gd.getScore());
                    gd.saveGameState(words, gd.getScore(), gd.getMissedWords(), gd.getTyppedWords(), mainMenu.getCurrentLevel(), timer);
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && game) {
                    paused = !paused;  // Przełącznik pauzy
                }

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    mainMenu.level(window, newVectorFrequency, speed, event);
                    mainMenu.language(window, event,gd);
                    mainMenu.startbtn(window, newVectorFrequency, speed, paused, event, timer);
                    mainMenu.font(window, gd ,font, event);
                    mainMenu.load(window, event, gd,font, paused, timer, speed, newVectorFrequency, words);
                    mainMenu.exit(window, event);
                }
        }

        //menu
        game = mainMenu.start(window, paused, event);
        if (!game && !end) {
            window.clear();
            mainMenu.drawMenu(window, font,gd);
            displayBestScore(font, window);
                window.display();
            }

            if (game) {
                timerText.setString(timer.getTimeAsString());
                timer.update(paused);}

                //dodawanie slow do wektora
                if (!paused) words += WordManager::tempVec(window, font, wordSize, newVectorFrequency, mainMenu);

                if (!paused) {
                    //kursor
                    static sf::Time text_effect_time;
                    static bool show_cursor;

                    text_effect_time += clock_cursor.restart();

                    if (text_effect_time >= sf::seconds(0.5f)) {
                        show_cursor = !show_cursor;
                        text_effect_time = sf::Time::Zero;
                    }

                    textBox.setString(debugInput + (show_cursor ? '_' : ' '));
                    textBox.setFillColor(sf::Color::Yellow);
                    textBox.setPosition(280, 72);
                    //~~~~~~~~~~~~~~~~~~~~~~~~


                    window.clear(sf::Color::White);
                    window.draw(background);
                    window.draw(frog);
                    window.draw(textBox);
                    window.draw(timerText);

                    for (auto iter = words.begin(); iter != words.end(); iter++) {
                        iter->text.move(speed, 0);
                        if (iter->isDisplaying()) {
                            window.draw(*iter);
                        }
                        if ((*iter).getPosition() > 1344 && (*iter).isDisplaying()) {
                            missedWords++;
                            gd.setMissedWords(gd.getMissedWords() + 1);
                            words.erase(iter);
                            missedCounter.setString("missed: " + std::to_string(missedWords));
                        }

                        if ((*iter).getPosition() > window.getSize().x - 500) {
                            (*iter).text.setFillColor(sf::Color::Yellow);
                        }
                        if ((*iter).getPosition() > window.getSize().x - 200) {
                            (*iter).text.setFillColor(sf::Color::Red);
                        }
                    }
                    //temp
                    missedCounter.setString("missed: " + std::to_string(gd.getMissedWords()));
                    typpedCounter.setString("typped: " + std::to_string(gd.getTyppedWords()));
                    scoreCounter.setString("score: " + std::to_string(gd.getScore()));

                    window.draw(missedCounter);
                    window.draw(typpedCounter);
                    window.draw(scoreCounter);
                    Frog::frogUpdate(missedWords, window);

                    if (missedWords > 20) {
                        saveBestScore(gd.getScore());
                        game = false;
                        end = true;
                        paused = true;
                        texture.loadFromFile("../assets/gameover2.jpg");
                        window.draw(background);
                    }

                    window.display();
                }
            }
        }






