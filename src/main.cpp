#include <iostream>

#include "../inc/Moacreature.h"
#include "../inc/Collections_Moacreature.h"
#include <SFML/Graphics.hpp>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {

    /**
    Collections_Moacreature troupeau_de_moa;

    //Premier Moacreature
    auto test = Moacreature(001, "Patrick", 10, 100, 1, 30000 );
    test.displayInfo();
    troupeau_de_moa.obtient(&test);

    // Deuxieme Moacreature
    auto test3 = Moacreature (002, "Bob", 10, 10, 75, 12 );
    test3.displayInfo();

    troupeau_de_moa.obtient(&test3);
    //test.total_creature();
    troupeau_de_moa.lister_creature();


    std::cout << std::endl;
    std::cout << "Attaque de " << test.getName() << " par " << test3.getName() <<" de degats " <<test.getAttack()-test3.getDefense() << std::endl;
    std::cout << std::endl;
    test.attaque_simple(test3);
    std::cout << std::endl;
    ;

    //Liste de créature.

    return 0;
    */
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
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
}