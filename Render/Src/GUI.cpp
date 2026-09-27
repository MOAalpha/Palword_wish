//
// Created by mathe on 18/09/2026.
//

#include "../Inc/GUI.h"
#include <SFML/Graphics.hpp>

void GUI::addPicture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Erreur chargement image!" << std::endl;
        return;
    }
    sf::Sprite premiere_creature(texture);
    this->screen.setPosition({200, 200});
}

void GUI::run() {
    sf::Texture texture;
    if (!texture.loadFromFile("../background/image_pokedex-20260914/pokemon/1.01.png")) {
        std::cerr << "Erreur chargement image" << std::endl;
        return;
    }
    sf::Texture background_image;
    if (!background_image.loadFromFile("../background/img.png")) {
        std::cerr << "Erreur chargement image" << std::endl;
        return;
    }
    sf::Sprite background(background_image);
    background.setScale(800.f / background_image.getSize().x,600.f / background_image.getSize().y);
    background.setPosition(0, 0);
    sf::Sprite premiere_creature(texture);
    premiere_creature.setPosition(200, 200);
    float vitesse = 0.1;

    while (this->screen.isOpen()) {
        sf::Vector2f deplacement(0.f, 0.f);
        sf::Event event{};
        while (this->screen.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->screen.close();

        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            deplacement.y -= vitesse;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            deplacement.y += vitesse;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            deplacement.x -= vitesse;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            deplacement.x += vitesse;
        }

        // 1. Calcul de la nouvelle position théorique
        sf::Vector2f nouvelle_pos = premiere_creature.getPosition() + deplacement;

        // 2. Récupération de la taille du sprite (pour éviter qu'il ne sorte partiellement à droite/bas)
        sf::FloatRect bounds = premiere_creature.getGlobalBounds();

        // 3. Blocage aux bordures de la fenêtre
        if (nouvelle_pos.x < 0.f) {
            nouvelle_pos.x = 0.f;
        }
        if (nouvelle_pos.x + bounds.width > this->screen.getSize().x) {
            nouvelle_pos.x = this->screen.getSize().x - bounds.width;
        }
        if (nouvelle_pos.y < 0.f) {
            nouvelle_pos.y = 0.f;
        }
        if (nouvelle_pos.y + bounds.height > this->screen.getSize().y) {
            nouvelle_pos.y = this->screen.getSize().y - bounds.height;
        }

        // 4. Application de la position finale
        premiere_creature.setPosition(nouvelle_pos);
        this->screen.clear();
        this->screen.draw(background);
        this->screen.draw(premiere_creature);
        this->screen.display();
    }
}
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

        }
        sf::Vector2f deplacement(0.f, 0.f);
        float vitesse = 1.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            deplacement.y -= vitesse;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            deplacement.y += vitesse;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            deplacement.x -= vitesse;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            deplacement.x += vitesse;
        }

        // 1. Calcul de la nouvelle position théorique
        sf::Vector2f nouvelle_pos = premiere_creature.getPosition() + deplacement;

        // 2. Récupération de la taille du sprite (pour éviter qu'il ne sorte partiellement à droite/bas)
        sf::FloatRect bounds = premiere_creature.getGlobalBounds();

        // 3. Blocage aux bordures de la fenêtre
        if (nouvelle_pos.x < 0.f) {
            nouvelle_pos.x = 0.f;
        }
        if (nouvelle_pos.x + bounds.width > window.getSize().x) {
            nouvelle_pos.x = window.getSize().x - bounds.width;
        }
        if (nouvelle_pos.y < 0.f) {
            nouvelle_pos.y = 0.f;
        }
        if (nouvelle_pos.y + bounds.height > window.getSize().y) {
            nouvelle_pos.y = window.getSize().y - bounds.height;
        }

        // 4. Application de la position finale
        premiere_creature.setPosition(nouvelle_pos);

        window.clear();
        window.draw(premiere_creature);
        window.display();
    }
    return 0;
}