//
// Created by belou on 27/09/2026.
//

#ifndef PALWORD_WISH_GAMEENGINE_H
#define PALWORD_WISH_GAMEENGINE_H
#include "GameState.h"
#include "Welcome.h"
#include "../../Creature/inc/mon_MoaDex.h"
#include "../../Render/Inc/GUI.h"


class GameEngine {
private:
    GUI renderEngine;
    GameState* currentState=nullptr;
    GameState* nextState=nullptr;

public:
    mon_MoaDex* player=new mon_MoaDex();

    GameEngine();
    ~GameEngine() = default;
    void setGameState(GameState* new_gameState);
    void updateState();
    GameState* getGameState() const;
    GUI *getRenderEngine();
    void run();
};



#endif //PALWORD_WISH_GAMEENGINE_H
