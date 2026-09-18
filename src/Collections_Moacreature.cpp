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
        if (MOA != nullptr) {
            std::cout << MOA->getName() << " " << MOA->getId() << std::endl;
        }
    }
}



Collections_Moacreature::~Collections_Moacreature() {
    std::cout << "Collection supprimee! "<<std::endl;
}