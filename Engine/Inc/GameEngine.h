//
// Created by belou on 27/09/2026.
//

#ifndef PALWORD_WISH_GAMEENGINE_H
#define PALWORD_WISH_GAMEENGINE_H
#include "GameState.h"
#include "Welcome.h"
#include "../../Render/Inc/GUI.h"


class GameEngine {
private:
    GUI renderEngine;
    GameState* currentState=nullptr;
public:
    GameEngine();
    ~GameEngine() = default;
    void setGameState(GameState* new_gameState);
    GameState* getGameState() const;
    GUI *getRenderEngine();
};



#endif //PALWORD_WISH_GAMEENGINE_H
