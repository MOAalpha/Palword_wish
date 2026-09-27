//
// Created by mathe on 14/09/2026.
//

#include "../inc/mon_MoaDex.h"

#include <algorithm>
#include <iostream>
#include <ostream>

void mon_MoaDex::obtenir_creature(string nom_de_moacreature) {
    Moacreature* creature_trouvee = dico->chercher_moacreature(nom_de_moacreature);
    if (creature_trouvee == nullptr) {
        std::cerr << "Cette creature n'existe pas (encore) : "<< nom_de_moacreature <<"!" << std::endl;
        return;
    }
    if (Collections_Moacreature::trouver_la_creature(creature_trouvee->getId()) == 0) {
        std::cout << "Existe deja !" << std::endl;
        return;
    }
    mon_MoaDex::collection.push_back(creature_trouvee);
    std::cout << "Nouvelle creature ajoutee a la liste : "<< creature_trouvee->getName() << std::endl;
}

void mon_MoaDex::supprimer_creature(string nom_de_moacreature) {
    Moacreature* creature_trouvee = dico->chercher_moacreature(nom_de_moacreature);
    if (creature_trouvee == nullptr) {
        std::cerr << "Cette creature n'existe pas (encore) : "<< nom_de_moacreature <<"!" << std::endl;
        return;
    }
    if (mon_MoaDex::trouver_la_creature(creature_trouvee->getId()) == 0) {
        auto it = std::find_if(collection.begin(), collection.end(),
    [&](Moacreature* Creature){ return Creature->getName() == creature_trouvee->getName(); });

        if (it != collection.end()) {
            delete *it;
            collection.erase(it);
            std::cout << creature_trouvee->getName() << " a ete relachee dans la nature !" << std::endl;
        }else {
            std::cerr << "La creature ne faisait pas partie de la collection" << std::endl;
        }
    }else {
        std::cerr << "Pb : La créature n'a pas été trouvée..." << std::endl;
    };
    }

Moacreature *mon_MoaDex::chercher_moacreature(int id) {
    for ( Moacreature *moacreature : collection) {
        if (moacreature->getId() == id) {
            return moacreature;
        }
    }
    return nullptr;
}

Moacreature *mon_MoaDex::chercher_moacreature(std::string nom_de_moacreature) {
    for ( Moacreature *moa_creature : collection) {
        if (moa_creature->getName() == nom_de_moacreature) {
            return moa_creature;
        }
    }
    return nullptr;
}

int mon_MoaDex::regenerer_moacreature(std::string nom_de_moacreature) {
    for ( Moacreature *moacreature : collection) {
        if (moacreature->getHitPoint() != moacreature->getHitPointMax() ) {
            moacreature->setHitPoint(moacreature->getHitPointMax());
        }
    }
    return 0;
}
