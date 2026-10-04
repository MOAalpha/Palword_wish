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
    std::deque<sf::Texture> textures;//deque pour sauvegarder l'ordre des adresses enregistrées
    std::vector<sf::Sprite> to_draw;
    std::vector<int> id;

    sf::Sprite background;
    sf::Texture background_texture;
    bool background_has_changed=false;
    bool isCombat=false;

    sf::Sprite hero;
    sf::Texture hero_texture;
    std::deque<sf::Texture> hero_textures;
    std::deque<sf::Sprite> hero_sprites;
    std::deque<int> id_hero_creatures;


public:
    GUI();
    bool isOpen() {
        return screen.isOpen();
    }
    void changeBackground(std::string path);
    void changeHero(std::string path);
    void moveHero(float x, float y);
    void addPicture(std::string path, int x, int y, int id);
    void addPictureHero(std::string path, int x, int y, int id);
    void update();
    void draw();
    void setCombatMode(bool value);
    void setOnlyOneSprite(int id_creature_libre, int creature_hero);
    int search_contact();
    sf::Vector2f getScreenSize() const;
    void displayCollection();

    //void run();

    int afficher_fond();
};


#endif //PALWORD_WISH_GUI_H
