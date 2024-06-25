#include "Menu.h"
#include "GameData.h"
#include "Settings.h"

void Menu::drawMenu(sf::RenderWindow &window, sf::Font &font, GameData& data) {
    //best score
    if(!scoreTexture.loadFromFile("../assets/laur.png"))
        std::cout<<"error while loading image\n";
    auto scoreImage = sf::Sprite(scoreTexture);
    scoreImage.setPosition(0, 0);
    scoreImage.setScale(0.5f, 0.5f);
    //text
    levelTxt.setFont(font1);
    levelTxt.setFillColor(levelColor);
    levelTxt.setString(currentLevel);
    levelTxt.setPosition(1150, 183);

    //font
    font1.loadFromFile("../assets/Roboto-Medium.ttf");
    font2.loadFromFile("../assets/Minecraft.ttf");
    font3.loadFromFile("../assets/SourceCodePro-Black.ttf");
    fontTxt.setFont(font);
    fontTxt.setFillColor(sf::Color::Black);
    fontTxt.setString(data.getCurrentFont());
    fontTxt.setPosition(1150, 290);

    //file
    fileTxt.setFont(font1);
    fileTxt.setString(data.getCurrentFile());
    fileTxt.setFillColor(sf::Color::Black);
    fileTxt.setPosition(1160, 393);

    auto menuTexture = sf::Texture();
    if (!menuTexture.loadFromFile("../assets/menu-1.jpg")) std::cout << "can not load image \n";
    auto menuView = sf::Sprite(menuTexture);
    menuView.setScale(0.75, 0.75);
    sf::RectangleShape kwadrat;
    kwadrat.setSize(sf::Vector2f(280, 80));
    kwadrat.setPosition(1000, 485);
    window.draw(menuView);
    window.draw(levelTxt);
    window.draw(fontTxt);
    window.draw(fileTxt);
    window.draw(scoreImage);
    //window.draw(kwadrat);
}

bool Menu::start(sf::RenderWindow &window, bool& paused, sf::Event& event) {
    return game;
}


void Menu::level(sf::RenderWindow &window, int& vecFrequancy, float& speed, sf::Event& event) {
    sf::IntRect levelRect(1000, 160, 280, 80);
    if (levelRect.contains(event.mouseButton.x,event.mouseButton.y)) {
        if (currentLevel == "easy") {
            currentLevel = "medium";
            levelColor = sf::Color(254, 127, 0);
            vecFrequancy = 7;
            speed = 1;
        } else if (currentLevel == "medium") {
            currentLevel = "hard";
            levelColor = sf::Color::Red;
            vecFrequancy = 4;
            speed = 2;
        } else if (currentLevel == "hard") {
            currentLevel = "easy";
            levelColor = sf::Color::Green;
            vecFrequancy = 10;
        }
        levelTxt.setString(currentLevel);
        levelTxt.setFillColor(levelColor);
    }
}

void Menu::startbtn(sf::RenderWindow &window, int& vecFrequancy, float& speed, bool& paused, sf::Event& event, Timer& timer) {
    sf::IntRect start(1000, 55, 280, 80);
    if (start.contains(event.mouseButton.x,event.mouseButton.y)) {
        game = true;
        paused = false;
        timer.restart();
        timer.start();
    }
}

void Menu::font(sf::RenderWindow &window, GameData& data, sf::Font& font, sf::Event& event) {
    sf::IntRect levelRect(1000, 270, 280, 80);
    if (levelRect.contains(event.mouseButton.x,event.mouseButton.y)) {
        if (data.getCurrentFont() == "Font1") {
            data.setCurrentFont("Font2");
            font = font2;
            curFont = font2;
        } else if (data.getCurrentFont() == "Font2") {
            data.setCurrentFont("Font3");
            font = font3;
            curFont = font3;
        } else if (data.getCurrentFont() == "Font3") {
            data.setCurrentFont("Font1");
            font = font1;
            curFont = font1;
        }
        fontTxt.setString(data.getCurrentFont());
        fmt::println("{}", data.getCurrentFont());
    }
}

void Menu::language(sf::RenderWindow &window, sf::Event& event, GameData& gd) {
    sf::IntRect levelRect(1000, 370, 280, 80);
    if (levelRect.contains(event.mouseButton.x,event.mouseButton.y)) {
        if (gd.getCurrentFile() == "english") {
            gd.setCurrentFile("polish");
            file = "../slowa.txt";
        } else if (gd.getCurrentFile() == "polish") {
            gd.setCurrentFile("java");
            file = "../java1.txt";
        } else if (gd.getCurrentFile() == "java") {
            gd.setCurrentFile("english");
            file= "../words.txt";
        }
        fileTxt.setString(gd.getCurrentFile());
        Settings::setFile(file);
    }
}

const std::string &Menu::getFile() const {
    return file;
}

void Menu::exit(sf::RenderWindow &window, sf::Event & event) {
    sf::IntRect levelRect(1000, 585, 280, 80);
    if (levelRect.contains(event.mouseButton.x,event.mouseButton.y)) {

        window.close();
    }
}

int Menu::levelPoints() {
    if (currentLevel == "easy") {
        return 10;
    } else if (currentLevel == "medium") {
        return 20;
    } else if (currentLevel == "hard") {
        return 40;
    }
}

const std::string &Menu::getCurrentLevel() const {
    return currentLevel;
}

void Menu::load(sf::RenderWindow &window, sf::Event &event, GameData &gd, sf::Font& font, bool& paused, Timer& timer, float & newspeed,int& vec, std::vector<Text>& words) {
    sf::IntRect levelRect(1000, 485, 280, 80);
    if (levelRect.contains(event.mouseButton.x,event.mouseButton.y)) {
        gd.loadGameState(font, words);
        if (gd.getCurrentFont() == "Font1") {
            font = font1;
            curFont = font1;
        } else if (gd.getCurrentFont() == "Font2") {
            font = font2;
            curFont = font2;
        } else if (gd.getCurrentFont() == "Font3") {
            font = font3;
            curFont = font3;
        }

        if (gd.getCurrentFile() == "english") {
            Settings::setFile("../words.txt");
        } else if (gd.getCurrentFile() == "polish") {
            Settings::setFile("../slowa.txt");
        } else if (gd.getCurrentFile() == "java") {
            Settings::setFile("../java1.txt");
        }

        newspeed = gd.getSpeed();
        vec = gd.getNewVectorFrequency();


        game = true;
        paused = false;
        timer.setCurrentTime(gd.getTime());
        timer.start();
    }
}



