//
// Created by belou on 04/10/2026.
//

#ifndef PALWORD_WISH_CAPTURE_H
#define PALWORD_WISH_CAPTURE_H
#include "../Inc/GameEngine.h"
#include "../Inc/GameState.h"

/**
* Cette classe représente la partie Exploration du jeu.
*/
class Capture :public GameState {
    private:
        GameEngine* my_gameEngine = nullptr;
        int id_creature;

    public:
        Capture(GameEngine* gameEngine, int id);

        void key_actions() override;
        //Gestion de l'état en cours
        void update() override;
        //Gestion de l'affichage
        void render() override;
};


#endif //PALWORD_WISH_CAPTURE_H
