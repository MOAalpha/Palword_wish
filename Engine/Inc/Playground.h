//
// Created by belou on 04/10/2026.
//

#ifndef PALWORD_WISH_PLAYGROUND_H
#define PALWORD_WISH_PLAYGROUND_H
#include "GameEngine.h"
#include "GameState.h"

/**
 * Cette classe représente la partie Exploration du jeu.
 */
class Playground: public GameState {
private:
    GameEngine* my_gameEngine = nullptr;
    bool already_add; //to add creature once

public:
    Playground(GameEngine* gameEngine);

    void key_actions() override;
    //Gestion de l'état en cours
    void update() override;
    //Gestion de l'affichage
    void render() override;
};


#endif //PALWORD_WISH_PLAYGROUND_H
