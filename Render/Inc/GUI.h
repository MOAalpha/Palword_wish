//
// Created by mathe on 18/09/2026.
//

#ifndef PALWORD_WISH_GUI_H
#define PALWORD_WISH_GUI_H
#include <deque>
#include <iostream>
#include <mutex>
#include <ostream>

#include <SFML/Graphics.hpp>


class GUI {
private:
    sf::RenderWindow screen;
    std::deque<sf::Texture> textures;
    std::vector<sf::Sprite> to_draw;

public:
    GUI();
    bool isOpen() {
        return screen.isOpen();
    }
    void addPicture(std::string path);
    void update();
    void draw();

    //void run();

    int afficher_fond();
};


#endif //PALWORD_WISH_GUI_H
