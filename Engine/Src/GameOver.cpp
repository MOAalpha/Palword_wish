//
// Created by belou on 04/10/2026.
//

#include "../Inc/GameOver.h"

#include <iostream>
#include <ostream>


GameOver::GameOver(GameEngine* gameEngine):my_gameEngine(gameEngine) {
    std::cout << "End of the journey. You lost everything! Press SPACE to restart !" << std::endl;
    auto* render = my_gameEngine->getRenderEngine();
    render->changeBackground("../background/GameOver.jfif");

}

void GameOver::render() {

}

void GameOver::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        my_gameEngine->setGameState(new Welcome(my_gameEngine));
        return;
    }
}

void GameOver::key_actions() {

}