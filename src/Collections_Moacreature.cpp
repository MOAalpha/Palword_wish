//
// Created by mathe on 11/09/2026.
//

#include "../inc/Collections_Moacreature.h"

#include <algorithm>

#include "../inc/Moacreature.h"
#include <iostream>
#include <ostream>

int Collections_Moacreature::trouver_la_creature(int id) {
    for ( Moacreature* MOA : Collections_Moacreature::collection) {
        if (MOA->getId() == id) {
            //MOA.displayInfo();
            return 0;
        }
    }
    //std::cout << "Cet identifiant est inconnu! "<<std::endl;
    return -1;
}


int Collections_Moacreature::trouver_la_creature(string name) {
    for ( Moacreature* MOA : Collections_Moacreature::collection) {
        if (MOA->getName() == name) {
            MOA->displayInfo();
            return 0;
        }
    }
    std::cout << "Ce nom est inconnu! "<<std::endl;
    return -1;
}

void Collections_Moacreature::lister_creature() {
    if (Collections_Moacreature::collection.empty()) {
        std::cout << "Aucune creature ! Terrible... "<<std::endl;
        return;
    }

    std::cout << "Voici la liste des creatures : "<<std::endl;
    for (Moacreature* MOA : Collections_Moacreature::collection) {
        std::cout << MOA->getName() << " " << MOA->getId() << std::endl;
    }
}

void Collections_Moacreature::obtient(Moacreature* MOA) {
    if (MOA == nullptr) {
        std::cout << "Erreur obtention "<<std::endl;
        return;
    }
    if (Collections_Moacreature::trouver_la_creature(MOA->getId()) == 0) {
        std::cout << "Existe deja !" << std::endl;
        return;
    }
    Collections_Moacreature::collection.push_back(MOA);
    std::cout << "Nouvelle creature ajoutee a la liste : "<< MOA->getName() << std::endl;
    //MOA->displayInfo();
}
void Collections_Moacreature::perd(Moacreature* MOA) {
    if (MOA == nullptr) {
        std::cout << "Erreur recuperation creature "<<std::endl;
        return;
    }
    if (Collections_Moacreature::trouver_la_creature(MOA->getId()) == 0) {
        auto it = std::find_if(collection.begin(), collection.end(),
    [&](Moacreature* m) {
        return m->getName() == MOA->getName();
    });

        if (it != collection.end()) {
            int index = std::distance(collection.begin(), it);
            //collection.erase(index);
            std::cout << MOA->getName() << " a ete relachee dans la nature !" << std::endl;
        }
        return;
    }

}

Collections_Moacreature::~Collections_Moacreature() {
    std::cout << "Collection supprimee! "<<std::endl;
}