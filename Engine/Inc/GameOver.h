//
// Created by belou on 04/10/2026.
//

#ifndef PALWORD_WISH_GAMEOVER_H
#define PALWORD_WISH_GAMEOVER_H

#include "../Inc/GameEngine.h"
#include "../Inc/GameState.h"

class GameOver : public GameState {
    private:
        GameEngine* my_gameEngine=nullptr;
    public:
        GameOver(GameEngine* gameEngine);

        void key_actions() override;
        void render() override;
        void update() override;
};



#endif //PALWORD_WISH_GAMEOVER_H
