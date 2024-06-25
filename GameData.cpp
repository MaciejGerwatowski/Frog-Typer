


#include "GameData.h"

void ustawZmienne(){

}

void GameData::saveGameState(std::vector<Text>& words, int score, int missed, int typped, std::string level , Timer timer) {
    std::ofstream file("../assets/save.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: "  << std::endl;
        return;
    }

    file << score << " " << level << " " << missed << " " << typped << " " << currentFont << " "<< currentFile << " " << timer.getCurrentTime().asSeconds() << "\n";
    for (auto& word : words) {
        file << word.getWord() << " " << word.getPosition() <<" " << word.getY() <<  "\n";
    }
    file.close();
}

void GameData::loadGameState(sf::Font &font,std::vector<Text>& words) {
    float xF, yF;
    std::string levelF, fontF, languageF, wordF;
    double timeF;

    sf::Font font1;
    font1.loadFromFile("../assets/Roboto-Medium.ttf");

    // Otwieranie pliku
    std::ifstream file("../assets/save.txt");

    if (file.is_open()) {
        // Wczytywanie stałych danych
        file >> score >> currentLevel >> missedWords >> typpedWords >> currentFont >> currentFile >> time;

        std::cout << "Score: " << score << ", Level: " << currentLevel << std::endl;
        std::cout << "Missed: " << missedWords << ", Typped: " << typpedWords << std::endl;
        std::cout << "Font: " << currentFont << ", Language: " << currentFile << std::endl;
        std::cout << "Time: " << time << std::endl;


        if(currentLevel == "easy"){
            speed = 1.f;
            newVectorFrequency = 10;
        }
        if(currentLevel == "medium"){
            newVectorFrequency = 7.f;
            speed = 1;
        }
        if(currentLevel == "hard"){
            newVectorFrequency = 4;
            speed = 2;
        }



        // Wczytywanie danych w pętli
        /*while (file >> wordF >> xF >> yF) {
            auto text1 = Text(0);
            text1.spawn(font,xF,yF, wordF);
            words.push_back(text1);
            std::cout << "Word: " << wordF << ", X: " << xF << ", Y: " << yF << std::endl;
        }*/

        file.close();



    } else {
        std::cout << "Nie można otworzyć pliku: " << "../assets/save.txt" << std::endl;
    }
}


int GameData::getWordSize() const {
    return wordSize;
}

void GameData::setWordSize(int wordSize) {
    GameData::wordSize = wordSize;
}

float GameData::getSpeed() const {
    return speed;
}

void GameData::setSpeed(float speed) {
    GameData::speed = speed;
}

int GameData::getNewVectorFrequency() const {
    return newVectorFrequency;
}

void GameData::setNewVectorFrequency(int newVectorFrequency) {
    GameData::newVectorFrequency = newVectorFrequency;
}

bool GameData::isPaused() const {
    return paused;
}

void GameData::setPaused(bool paused) {
    GameData::paused = paused;
}

int GameData::getMissedWords() const {
    return missedWords;
}

void GameData::setMissedWords(int missedWords) {
    GameData::missedWords = missedWords;
}

int GameData::getTyppedWords() const {
    return typpedWords;
}

void GameData::setTyppedWords(int typpedWords) {
    GameData::typpedWords = typpedWords;
}

int GameData::getScore() const {
    return score;
}

void GameData::setScore(int score) {
    GameData::score = score;
}

float GameData::getTime() const {
    return time;
}

const std::vector<Text> &GameData::getCurrentWords() const {
    return currentWords;
}

const std::string &GameData::getCurrentLevel() const {
    return currentLevel;
}

const std::string &GameData::getCurrentFont() const {
    return currentFont;
}

void GameData::setCurrentFont(const std::string &currentFont) {
    GameData::currentFont = currentFont;
}

const std::string &GameData::getCurrentFile() const {
    return currentFile;
}

void GameData::setCurrentFile(const std::string &currentFile) {
    GameData::currentFile = currentFile;
}
