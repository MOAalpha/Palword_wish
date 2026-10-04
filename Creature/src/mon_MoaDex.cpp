//
// Created by mathe on 14/09/2026.
//

#include "../inc/mon_MoaDex.h"

#include <algorithm>
#include <iostream>
#include <ostream>

std::vector<Moacreature*> mon_MoaDex::getCollection() {
    return collection;
};
/**
 * Ajoute une nouvelle creature à la collection. Renvoie un message d'erreur si la créature n'existe pas dans le Moadex
 * ou si elle est déjà présente dans la collection.
 * @param nom_de_moacreature nom de la créature que l'on ajoute à la collection
 */
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

/**
 * Ajoute une nouvelle creature à la collection. Renvoie un message d'erreur si la créature n'existe pas dans le Moadex
 * ou si elle est déjà présente dans la collection.
 * @param id identifiant de la créature que l'on ajoute à la collection
 */
void mon_MoaDex::obtenir_creature(int id) {
    Moacreature* creature_trouvee = dico->chercher_moacreature(id);
    if (creature_trouvee == nullptr) {
        std::cerr << "Cette creature n'existe pas (encore) !" << std::endl;
        return;
    }
    if (Collections_Moacreature::trouver_la_creature(creature_trouvee->getId()) == 0) {
        std::cout << "Existe deja !" << std::endl;
        return;
    }
    mon_MoaDex::collection.push_back(creature_trouvee);
    std::cout << "Nouvelle creature ajoutee a la liste : "<< creature_trouvee->getName() << std::endl;
}

/**
 * Retire une creature à la collection. Renvoie un message d'erreur si la créature n'existe pas dans la dans la collection.
 * @param nom_de_moacreature nom de la créature que l'on souhaite retirer à la collection
 */
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

/**
 * Renvoie un pointeur vers la créature cherchée si elle fait partie de la collection, renvoie nullptr sinon.
 * @param id l'identifiant de la créature recherchée.
 * @return
 */
Moacreature *mon_MoaDex::chercher_moacreature(int id) {
    for ( Moacreature *moacreature : collection) {
        if (moacreature->getId() == id) {
            return moacreature;
        }
    }
    return nullptr;
}

/**
 * Renvoie un pointeur vers la créature cherchée si elle fait partie de la collection, renvoie nullptr sinon.
 * @param nom_de_moacreature le nom de la créature recherchée.
 * @return
 */
Moacreature *mon_MoaDex::chercher_moacreature(std::string nom_de_moacreature) {
    for ( Moacreature *moa_creature : collection) {
        if (moa_creature->getName() == nom_de_moacreature) {
            return moa_creature;
        }
    }
    return nullptr;
}

/**
 * Met les points de vie de  toutes les créatures de la liste aux points de vie maximum.
 * @return
 */
int mon_MoaDex::regenerer_moacreature() {
    for ( Moacreature *moacreature : collection) {
        if (moacreature->getHitPoint() != moacreature->getHitPointMax() ) {
            moacreature->setHitPoint(moacreature->getHitPointMax());
        }
    }
    return 0;
}
