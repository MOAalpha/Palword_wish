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
 * Modifie l'état du jeu.
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
    if (this->currentState != nullptr) {
        delete this->currentState;
    }
    this->currentState = new_gameState;
}




