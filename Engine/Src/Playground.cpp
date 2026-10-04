//
// Created by belou on 04/10/2026.
//

#include "../Inc/Playground.h"
#include <stdlib.h>
#include "../../Ressources/Ressources.h"
#include "../Inc/Capture.h"
#include "../Inc/Combat.h"

Playground::Playground(GameEngine* gameEngine):my_gameEngine(gameEngine), already_add(false) {
    std::srand(std::time(nullptr));   // initialise pour le choix des creatures
    std::cout << "Deplacez-vous pour trouver des creatures. Si vous etes sur une creature, vous pouvez la capturer avec C ou l'attaquer avec A." << std::endl;
        if (my_gameEngine == nullptr) {
            std::cerr << "Pas de gameEngine !!!" << std::endl;
            return;
        }
        auto* render = my_gameEngine->getRenderEngine();
        if (render == nullptr) {
            std::cerr << "Pas de renderEngine !!!" << std::endl;
            return;
        }
        render->changeBackground("../background/exploration.jpg");
        render->changeHero("../background/MOA2.jpg");
}


void Playground::key_actions() {
    auto id_creature=my_gameEngine->getRenderEngine()->search_contact();
    if (id_creature != -1 && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        my_gameEngine->setGameState(new Capture(this->my_gameEngine, id_creature));
    };
    if (id_creature != -1 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        my_gameEngine->setGameState(new Combat(this->my_gameEngine));
    }
}

static sf::Vector2f deplacement(0.f, 0.f);

void Playground::update() {
    float vitesse = 0.1;
    deplacement={0,0};


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
}
void Playground::render() {
    auto render = my_gameEngine->getRenderEngine();
    render->moveHero(deplacement.x, deplacement.y);
    sf::Vector2f screen_size = render->getScreenSize();
    int number_of_creatures = rand()%6 +1;
    if (!already_add) {
        for (int i = 0; i < number_of_creatures; i++){
            int id_creature = rand() % MAX_CREATURE + 1;
        std::string path = PATH_IMAGE + std::to_string(id_creature) + ".png";
        int x = rand() % static_cast<int>(screen_size.x);
        int y = rand() % static_cast<int>(screen_size.y);
        render->addPicture(path, x, y, id_creature);
        }
        already_add = true;
    }

}

/** A Adapter
sf::Sprite& premiere_creature = to_draw.back();
// 1. Calcul de la nouvelle position théorique
sf::Vector2f nouvelle_pos = premiere_creature.getPosition() + deplacement;

// 2. Récupération de la taille du sprite (pour éviter qu'il ne sorte partiellement à droite/bas)
sf::FloatRect bounds = premiere_creature.getGlobalBounds();

// 3. Blocage aux bordures de la fenêtre
if (nouvelle_pos.x < 0.f) {
    nouvelle_pos.x = 0.f;
}
auto screen_size = this->screen.getView().getSize();
if (nouvelle_pos.x + bounds.width > screen_size.x) {
    nouvelle_pos.x = screen_size.x - bounds.width;
}
if (nouvelle_pos.y < 0.f) {
    nouvelle_pos.y = 0.f;
}
if (nouvelle_pos.y + bounds.height > screen_size.y) {
    nouvelle_pos.y = screen_size.y - bounds.height;
}

// 4. Application de la position finale
premiere_creature.setPosition(nouvelle_pos);
*/