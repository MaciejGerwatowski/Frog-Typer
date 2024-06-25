
#include "Frog.h"

sf::Texture Frog::frogTexture;

sf::Sprite Frog::frogSpawn() {
    if(!frogTexture.loadFromFile("../assets/smiledforg.jpg"))
        std::cout<<"error while loading image\n";
    auto frogImage = sf::Sprite(frogTexture);
    frogImage.setPosition(85, 0);
    frogImage.setScale(0.5f, 0.5f);

    return frogImage;
}

void Frog::frogUpdate(int &missedWords, sf::RenderWindow &window) {

    auto frogImage = frogSpawn();

    if(missedWords > 5 && missedWords < 10){
        frogTexture.loadFromFile("../assets/midfrog.jpg");
        window.draw(frogImage);
    }
    if(missedWords >= 10 && missedWords < 15){
        frogTexture.loadFromFile("../assets/sadfrog.jpg");
        window.draw(frogImage);
    }
    if(missedWords >= 15){
        frogTexture.loadFromFile("../assets/darkfrog.jpg");
        window.draw(frogImage);
    }

}
