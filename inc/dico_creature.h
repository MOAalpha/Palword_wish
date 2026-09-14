//
// Created by mathe on 14/09/2026.
//

#ifndef PALWORD_WISH_LECTEURCSV_H
#define PALWORD_WISH_LECTEURCSV_H
#include <iostream>

#include "Collections_Moacreature.h"
using namespace std;

class dico_creature : public Collections_Moacreature {
    private:
    string nom_de_fichier_;
    static dico_creature *instance;
    dico_creature(const string nom_de_fichier);

public:
    dico_creature(dico_creature &autre_tentative) = delete;
    void operator=(const dico_creature &autre_tentative) = delete;
    static dico_creature *get_instance(const string& nom_de_fichier);
    Moacreature* obtenir_moacreature(const string& nom_de_moacreature);
    Moacreature* obtenir_moacreature(const int id);
};


#endif //PALWORD_WISH_LECTEURCSV_H
