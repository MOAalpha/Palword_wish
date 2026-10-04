//
// Created by belou on 27/09/2026.
//

#ifndef PALWORD_WISH_WELCOME_H
#define PALWORD_WISH_WELCOME_H
#include <iostream>
#include <ostream>

#include "../Inc/GameEngine.h"
#include "../Inc/GameState.h"

/**
 * Cette classe représente l'accueil du joueur.
 */

class GameEngine;
class Welcome : public GameState {
private:
    GameEngine* my_gameEngine=nullptr;
public:
    Welcome(GameEngine* gameEngine);

    void key_actions() override;
    void render() override;
    void update() override;
    void display_welcome();

};

#endif //PALWORD_WISH_WELCOME_H
