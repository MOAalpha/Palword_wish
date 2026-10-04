//
// Created by belou on 04/10/2026.
//

#ifndef PALWORD_WISH_COMBAT_H
#define PALWORD_WISH_COMBAT_H
#include "GameEngine.h"


class Combat : public GameState{
private:
    GameEngine* my_gameEngine = nullptr;

public:
    Combat(GameEngine* gameEngine);

    void key_actions() override;
    //Gestion de l'état en cours
    void update() override;
    //Gestion de l'affichage
    void render() override;
};


#endif //PALWORD_WISH_COMBAT_H
