//
// Created by belou on 04/10/2026.
//

#include "../Inc/Combat.h"
#include "../Inc/GameOver.h"

Combat::Combat(GameEngine* gameEngine):my_gameEngine(gameEngine) {
    std::cout<<"Essayer d'attaquer cette creature avec E'."<<std::endl;
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
    // Charger la collection du joueur
    for (auto creature : my_gameEngine->player->getCollection()) {
        std::string path = PATH_IMAGE + std::to_string(creature->getId())+".png";
        my_gameEngine->getRenderEngine()->addPictureHero(path, 0,0, creature->getId());
    }
    render->setCombatMode(true);
    my_gameEngine->player->obtenir_creature(49);
}

void Combat::update() {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        my_gameEngine->getRenderEngine()->setOnlyOneSprite(0, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        auto cible = my_gameEngine->player->getCollection();
        cible.at(0)->attaque_simple(*cible.at(cible.size()-1));
        if (cible.at(cible.size()-1)->getHitPoint()==1) {
            my_gameEngine->setGameState(new GameOver(my_gameEngine));
        }
    }

}
void Combat::key_actions() {

}

void Combat::render() {

}
