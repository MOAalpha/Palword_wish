//
// Created by belou on 04/10/2026.
//

#include "../Inc/Capture.h"

#include "../Inc/Playground.h"

Capture::Capture(GameEngine *gameEngine,  int id):my_gameEngine(gameEngine), id_creature(id)  {
    std::cout<<"Essayer de capturer cette creature avec la touche Y."<<std::endl;
    if (my_gameEngine == nullptr) {
        std::cerr << "Pas de gameEngine !!!" << std::endl;
        return;
    }
    auto* render = my_gameEngine->getRenderEngine();
    if (render == nullptr) {
        std::cerr << "Pas de renderEngine !!!" << std::endl;
        return;
    }
    render->changeBackground("../background/capture.jfif");
    render->setCombatMode(false);
}

void Capture::render() {

}

void Capture::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        std::cout << "La créature a été capturée." << std::endl;
        if (my_gameEngine->player == nullptr) {
            std::cerr << "Pas de joueur !" << std::endl;
            return;
        }
        mon_MoaDex& player = *my_gameEngine->player;
        player.obtenir_creature(this->id_creature);
        my_gameEngine->setGameState(new Playground(my_gameEngine));
        return;
    }
}

void Capture::key_actions() {

}
