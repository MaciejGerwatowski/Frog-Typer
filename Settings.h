#pragma once
#include <iostream>
class Settings {
public:
    Settings(){

    }
    static void setFile(std::string);
    static std::string getFile();



private:
    static std::string file;
};

