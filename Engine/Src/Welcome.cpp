//
// Created by belou on 27/09/2026.
//

#include "../Inc/Welcome.h"
#include "../Inc/Playground.h"

Welcome::Welcome(GameEngine* gameEngine):my_gameEngine(gameEngine) {
    {
        std::cout << "Welcome to MoaLand ! Here you can search and become friends with beautiful creatures called MoaCreature." << std::endl;
        std::cout << "En français, c'est mieux ! Tu peux démarrer la partie en appuyant sur Enter"<< std::endl;
        auto* render = my_gameEngine->getRenderEngine();
        render->changeBackground("../background/welcome.png");

    }
}
void Welcome::display_welcome() {

}

void Welcome::key_actions() {

}
void Welcome::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        my_gameEngine -> setGameState(new Playground(my_gameEngine));
    }
}
void Welcome::render() {
   }



