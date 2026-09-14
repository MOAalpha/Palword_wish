#include <iostream>

#include "../inc/Moacreature.h"
#include "../inc/Collections_Moacreature.h"
#include <SFML/Graphics.hpp>

#include "../inc/MoaDex.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
/**
 * Ce main est actuellement un ensemble de tests dont les resultats sont visibles dans la console
 * @return
 */
int main() {

    //Collection de creature
    auto troupeau_de_moa = new Collections_Moacreature();

    //Premier Moacreature
    auto test = Moacreature(001, "Patrick", 10, 100, 1, 30000 );
    test.displayInfo();
    troupeau_de_moa->obtient(&test);

    // Deuxieme Moacreature
    auto test3 = Moacreature (002, "Bob", 10, 10, 75, 12 );
    test3.displayInfo();
    troupeau_de_moa->obtient(&test3);
    troupeau_de_moa->lister_creature();


    //TEST ATTAQUE
    std::cout << std::endl;
    std::cout << "Attaque de " << test.getName() << " par " << test3.getName() <<" de degats " <<test.getAttack()-test3.getDefense() << std::endl;
    std::cout << std::endl;
    test.attaque_simple(test3);
    std::cout << std::endl;
    ;

    //Liste de créature.

    return 0;

    /*
    //TEST de l'interface graphique

    sf::RenderWindow window(sf::VideoMode(800, 600), "MOACREATURE");
    sf::CircleShape shape(150.f);
    shape.setFillColor(sf::Color::Red);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
    */

    //Test Singleton :
    //Collections_Moacreature troupeau_de_moa;
    MoaDex* mon_troupeau = MoaDex::get_instance("../background/pokedex.csv");
    MoaDex* test_singleton = MoaDex::get_instance("Louche");
    MoaDex* autre_test = MoaDex::get_instance("kglsfghfdjkhgdk");
    //mon_troupeau, test_singleton, autre_test pointent vers la meme reference, meme si le fichier est différent
    // ie aucune nouvelle instance n'est créé

    // Test ajout/retrait d'une collection de creatures. Machine
    autre_test->obtient(&test);
    autre_test->lister_creature();
    autre_test->perd(test_singleton->chercher_moacreature("Metapod"));

    Moacreature* Charizard = test_singleton->chercher_moacreature("Metapod");
    if (Charizard == nullptr) {
        std::cout << Charizard->getName()<<" n'est plus dans la collection" << std::endl;
    }else {
        Charizard->displayInfo();
    }
    //Non fonctionnel
}
