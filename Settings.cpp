
#include "Settings.h"

#include <utility>
std::string Settings::file = "../words.txt";
void Settings::setFile(std::string string) {
    file = std::move(string);
}

std::string Settings::getFile(){
    return file;
}

