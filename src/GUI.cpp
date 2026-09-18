//
// Created by mathe on 18/09/2026.
//

#include "../inc/GUI.h"
#include <SFML/Graphics.hpp>

int GUI::afficher_fond() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MOACREATURE");
    //sf::CircleShape shape(150.f);
    //shape.setFillColor(sf::Color::Red);
    sf::Texture texture;
    if (!texture.loadFromFile("../background/image_pokedex-20260914/pokemon/1.01.png")) {
        std::cerr << "Erreur chargement image" << std::endl;
        return 1;
    }
    sf::Sprite premiere_creature(texture);
    premiere_creature.setPosition(200, 200);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Z || sf::Keyboard::Up :
                        premiere_creature.setPosition(premiere_creature.getPosition().x, premiere_creature.getPosition().y-10);
                        break;
                    case sf::Keyboard::S || sf::Keyboard::Down :
                        premiere_creature.setPosition(premiere_creature.getPosition().x, premiere_creature.getPosition().y+10);
                        break;
                    case sf::Keyboard::Q || sf::Keyboard::Left :
                        premiere_creature.setPosition(premiere_creature.getPosition().x+10, premiere_creature.getPosition().y);
                        break;
                    case sf::Keyboard::D || sf::Keyboard::Right :
                        premiere_creature.setPosition(premiere_creature.getPosition().x-10, premiere_creature.getPosition().y);
                        break;

                }
            }
        }
        window.clear();
        window.draw(premiere_creature);
        window.display();
    }
    return 0;
}