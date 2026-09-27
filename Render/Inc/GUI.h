//
// Created by mathe on 18/09/2026.
//

#ifndef PALWORD_WISH_GUI_H
#define PALWORD_WISH_GUI_H
#include <iostream>
#include <ostream>

#include <SFML/Graphics.hpp>


class GUI {
private:
    sf::RenderWindow screen;

public:
    GUI():screen(sf::VideoMode(800, 600), "MoaLand") {
        std::cout<<"Initialisation Interface Graphique en cours !"<<std::endl;
    };

    void addPicture(std::string path);

    void run();

    int afficher_fond();
};


#endif //PALWORD_WISH_GUI_H
