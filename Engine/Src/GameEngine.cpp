//
// Created by belou on 27/09/2026.
//

#include "../Inc/GameEngine.h"

#include <iostream>
#include <ostream>

GameEngine::GameEngine():renderEngine(GUI()), currentState(new Welcome(this)) {
    std::cout << "Welcome !" << std::endl;
}

/**
 * getter sur l'état du jeu.
 * @return l'état du jeu
 */
GameState* GameEngine::getGameState() const {
    if (currentState == nullptr) {
        std::cerr << "Etat du jeu non-défini !" << std::endl;
    }
    return currentState;
}

GUI *GameEngine::getRenderEngine(){
   return &renderEngine;
}

/**
 * Modifie l'état du jeu. enregistre l'état dans nextState et attend l'appel à updateState pour mettre à jour,
 * pour éviter de modifier pendant l'exécution d'une méthode associée à l'état
 * * Si l'état fournie est nullptr, l'état n'est pas mis à jour.
 * @param new_gameState change l'état du jeu
 */
void GameEngine::setGameState(GameState* new_gameState) {
    if (new_gameState == nullptr ) {
        std::cerr << "Pas de nouvel état défini !" << std::endl;
        return;
    }
    if (new_gameState == this->currentState) {
        std::cerr << "Même état !" << std::endl;
        return;
    }
    if (this->nextState != nullptr) {
        delete this->nextState;
    }
    this->nextState = new_gameState;
}

/**
 * Change l"Etat courant à la fin de l'execution de toutes les méthodes
 * (update et render)
 *
 */
void GameEngine::updateState() {
    if (nextState != nullptr) {
        delete currentState;
        currentState = nextState;
        nextState = nullptr;
    }
}

/** Execute le jeu :
 *
 */
void GameEngine::run() {
    auto* render = getRenderEngine();
    //render->addPicture("../background/healthGauge.png");
    //render->addPicture("../background/image_pokedex-20260914/pokemon/3.03.png");

    while (render->isOpen()) {
        auto currentState = getGameState();
        currentState->update();
        currentState->render();
        currentState->key_actions();
        render->update();
        render->draw();
        updateState();
    }
}




