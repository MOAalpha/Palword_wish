//
// Created by belou on 27/09/2026.
//

#ifndef PALWORD_WISH_GAME_ENGINE_H
#define PALWORD_WISH_GAME_ENGINE_H

/**
 * Cette classe est une interface représentant un état du jeu.
 * Il y a 5 états : Welcome, Playground, Capture, Battle, GameOver.
 */
class GameState {
    public:
    //Gestion des boutons
    virtual void key_actions()=0;
    //Gestion de l'état en cours
    virtual void update()=0;
    //Gestion de l'affichage
    virtual void render()=0;
    virtual ~GameState() = default;
};


#endif //PALWORD_WISH_GAME_ENGINE_H
