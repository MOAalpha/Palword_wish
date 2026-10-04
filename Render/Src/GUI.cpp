//
// Created by mathe on 18/09/2026.
//

#include "../Inc/GUI.h"
#include <SFML/Graphics.hpp>

#include "../../Engine/Inc/Combat.h"


GUI::GUI():screen(sf::VideoMode(800, 600), "MoaLand") {
    std::cout<<"Initialisation Interface Graphique en cours !"<<std::endl;
};

/**
 * Ajoute la texture à la liste des Sprites à afficher
 * @param path emplacement du fichier image à dessiner
 */
void GUI::addPicture(std::string path, int x, int y, int id) {
    textures.emplace_back();
    if (!textures.back().loadFromFile(path)) {
        std::cerr << "Erreur chargement image!" << std::endl;
        return;
    }
    sf::Sprite new_sprite(textures.back());
    new_sprite.setPosition(x, y);
    to_draw.push_back(new_sprite);
    this->id.push_back(id);

}
/**
 * Ajoute la texture à la liste des Sprites à afficher
 * @param path emplacement du fichier image à dessiner
 */
void GUI::addPictureHero(std::string path, int x, int y, int id) {
    hero_textures.emplace_back();
    if (!hero_textures.back().loadFromFile(path)) {
        std::cerr << "Erreur chargement image!" << std::endl;
        return;
    }
    sf::Sprite new_sprite(hero_textures.back());
    new_sprite.setPosition(x, y);
    hero_sprites.push_back(new_sprite);
    this->id_hero_creatures.push_back(id);

}

void GUI::setOnlyOneSprite(int id_creature, int id_hero) {
    if (!this->isCombat) {
        int i = 0;
        for (auto& new_sprite : to_draw) {
            if (i==id_creature) {
                this->screen.draw(new_sprite);
                i=-1;
                break;
            }
            i++;

        }
        if (i == -1) {
            this->screen.draw(to_draw.at(to_draw.size()-1));
        }

    }else {
        int i = 0;
        for (auto& creature : hero_sprites) {
            creature.move(i*100, i*100);
            if (i == id_hero) {
                this->screen.draw(creature);
                i=-1;
                break;
            }
            i++;
        }
        if (i == -1) {
            this->screen.draw(hero_sprites.at(hero_sprites.size()-1));
        }
    }
}

/**
 * Sauvegarde le nouveau fond qui va être dessiné.
 * @param path emplacement du nouveau fond à charger
 */
void GUI::changeBackground(std::string path) {
    if (!background_texture.loadFromFile(path)) {
        std::cerr << "Erreur chargement fond !" << std::endl;
        return;
    }
    background = sf::Sprite(background_texture);
    background_has_changed = true;

}

/**
 * Sauvegarde le nouveau héros qui va être dessiné.
 * @param path emplacement du nouveau fond à charger
 */
void GUI::changeHero(std::string path) {
    int hero_size = 50;
    if (!hero_texture.loadFromFile(path)) {
        std::cerr << "Erreur chargement heros !" << std::endl;
        return;
    }
    hero = sf::Sprite(hero_texture);
    hero.setScale(hero_size/this->screen.getView().getSize().x ,hero_size/this->screen.getView().getSize().y );
}

void GUI::moveHero(float x, float y) {

    hero.move(x, y);
    sf::FloatRect bounds = hero.getGlobalBounds();
    auto position = hero.getPosition();
    auto screen_size = this->screen.getView().getSize();

    if (position.x < 0.f) {
        position.x = 0.f;
    }
    if (position.x + bounds.width > screen_size.x) {
        position.x = screen_size.x - bounds.width;
    }
    if (position.y < 0.f) {
        position.y = 0.f;
    }
    if (position.y + bounds.height > screen_size.y) {
        position.y = screen_size.y - bounds.height;
    }
    hero.setPosition(position);
}


void GUI::update() {
    sf::Event event{};
    while (this->screen.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->screen.close();
        if (event.type == sf::Event::Resized) {
            background_has_changed = true;
        }

    }
}

void GUI::draw() {
    this->screen.clear();
    // Fond
    if (background_has_changed) {
        background.setScale(800.f / background_texture.getSize().x,600.f / background_texture.getSize().y);
        background.setPosition(0, 0);
        background_has_changed = false;
    }
    this->screen.draw(background);
    this->screen.draw(hero);


    if (!this->isCombat) {
        for (auto& new_sprite : to_draw) {
            this->screen.draw(new_sprite);
        }
    }else {
        int i = 0;
        for (auto& creature : hero_sprites) {
            creature.setPosition(50,50);
            creature.move(i*100, i*100);
            i++;
            this->screen.draw(creature);
        }
    }
    this->screen.display();
}

void GUI::setCombatMode(bool value) {
    this->isCombat = value;
}

 sf::Vector2f GUI::getScreenSize() const {
    return this->screen.getView().getSize();
}

int GUI::search_contact() {
    sf::FloatRect heroBounds = hero.getGlobalBounds();

    for (size_t i = 0; i < to_draw.size(); i++) {
        if (to_draw.at(i).getGlobalBounds().intersects(heroBounds)) {
            return this->id.at(i);
        }
    }
    return -1;
}

/*
void run() {
    sf::Texture texture;
    if (!texture.loadFromFile("../background/image_pokedex-20260914/pokemon/1.01.png")) {
        std::cerr << "Erreur chargement image" << std::endl;
        return;
    }
    /*
    sf::Texture background_image;
    if (!background_image.loadFromFile("../background/welcome.png")) {
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
        //this->screen.draw(background);
        this->screen.draw(premiere_creature);
        float i =0;
        for (auto& new_sprite : to_draw) {
            new_sprite.setPosition(60,60);
            new_sprite.move(i*100, i*100);
            this->screen.draw(new_sprite);
            i++;
        }
        this->screen.display();
    }
}

*/

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

// Useless :
/*
 //Création du fond
 textures.emplace_back();
 sf::Texture& background_image = textures.back();
 if (!background_image.loadFromFile("../background/welcome.png")) {
     std::cerr << "Erreur chargement image" << std::endl;
     return;
 }
 sf::Sprite background(background_image);
 background.setScale(800.f / background_image.getSize().x,600.f / background_image.getSize().y);
 background.setPosition(0, 0);
 to_draw.push_back(background);
 */

/*
//Création de la première créature
textures.emplace_back();
sf::Texture& starter_creature = textures.back();
if (!starter_creature.loadFromFile("../background/image_pokedex-20260914/pokemon/1.01.png")) {
    std::cerr << "Erreur chargement image" << std::endl;
    return;
}
sf::Sprite premiere_creature(textures.back());
premiere_creature.setPosition(50, 50);
to_draw.push_back(premiere_creature);
*/