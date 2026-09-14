//
// Created by mathe on 14/09/2026.
//

#include "../inc/dico_creature.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
dico_creature* dico_creature::instance = nullptr;

/**
 * Constructeur de la classe
 * @param fileName Nom du fichier ou sont stockes les creatures, attendu au format CSV
 */
dico_creature::dico_creature(const string fileName):Collections_Moacreature() {

    std::cout << "*** Constructeur du MoaDex ***" << std::endl;

    std::ifstream file(fileName);
    if(!file.is_open()){
        std::cerr<<"File "<<fileName<<" not found "<<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        //    std::cout << line << std::endl;
        std::stringstream inputstringstream(line);
        std::string cell;
        std::vector<std::string> lineData;

        while(std::getline(inputstringstream,cell,',')){
            lineData.push_back(cell);
        }
        int id = std::stoi(lineData.at(0));
        double attackValue = std::stod(lineData.at(6));
        double hitPoint = std::stod(lineData.at(5));
        double defenseValue = std::stod(lineData.at(7));
        int generation = std::stoi(lineData.at(11));

        collection.push_back(new Moacreature(id, lineData.at(1),hitPoint,attackValue,
                                             defenseValue,generation));


    }
    collection.at(56)->displayInfo();
}

/**
 * Cree une unique instance de cette classe
 * @param nom_de_fichier designe le nom du fichier où sont stockes les creatures, fichier suppose sous format CSV.
 * @return une reference sur l'instance si elle existait deja, et en cree une sinon.
 */
dico_creature *dico_creature::get_instance(const string &nom_de_fichier) {
    if (instance == nullptr) {
        if (instance == nullptr) {
            instance = new dico_creature(nom_de_fichier);
        }
    }
    return instance;
}

/**
 * Permet de retrouver dans la **collection** de Moacreature une creature par son nom (reference sur string)
 * @param nom_de_creature le nom de la creature recherchee
 * @return une copie de la creature trouvee, ou nullptr le cas echeant.
 *
 *
 */
Moacreature* dico_creature::obtenir_moacreature(const string& nom_de_creature) {
    for ( Moacreature* moacreature : collection) {
        if (moacreature->getName() == nom_de_creature) {
            return new Moacreature(*moacreature);
        }
    }
    return nullptr;

}

/**
 * Permet de retrouver dans la **collection** de Moacreature une creature par son identifiant (id)
 * @param id
 * @return une copie de la creature trouvee, ou nullptr le cas echeant.
 *
 *
 */
Moacreature* dico_creature::obtenir_moacreature(const int id) {
    for ( Moacreature* moacreature : collection) {
        if (moacreature->getId() == id) {
            return new Moacreature(*moacreature);
        }
    }
    return nullptr;
}