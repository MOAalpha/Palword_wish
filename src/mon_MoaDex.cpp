//
// Created by mathe on 14/09/2026.
//

#include "../inc/mon_MoaDex.h"

#include <iostream>
#include <ostream>

void mon_MoaDex::obtenir_creature(string nom_de_moacreature) {
    Moacreature* creature_trouvee = dico->chercher_moacreature(nom_de_moacreature);
    if (creature_trouvee == nullptr) {
        std::cerr << "Cette creature n'existe pas (encore) : "<< nom_de_moacreature <<"!" << std::endl;
        return;
    }
    this->obtient(creature_trouvee);
}

void mon_MoaDex::supprimer_creature(string nom_de_moacreature) {
    Moacreature* creature_trouvee = dico->chercher_moacreature(nom_de_moacreature);
    if (creature_trouvee == nullptr) {
        std::cerr << "Cette creature n'existe pas (encore) : "<< nom_de_moacreature <<"!" << std::endl;
        return;
    }
    this->perd(creature_trouvee);
}
