//
// Created by mathe on 14/09/2026.
//

#ifndef PALWORD_WISH_LECTEURCSV_H
#define PALWORD_WISH_LECTEURCSV_H
#include <iostream>

#include "Collections_Moacreature.h"
using namespace std;

/**
 * Cette classe représente l'ensemble des creatures qui existent.
 * Elle recupere cette liste depuis un fichier CSV.
 */
class MoaDex : public Collections_Moacreature {
    private:
    string nom_de_fichier_;
    static MoaDex *instance;
    MoaDex(const string nom_de_fichier);

public:
    MoaDex(MoaDex &autre_tentative) = delete;
    void operator=(const MoaDex &autre_tentative) = delete;
    static MoaDex *get_instance(const string& nom_de_fichier);
    Moacreature* chercher_moacreature(const string& nom_de_moacreature);
    Moacreature* chercher_moacreature(const int id);
};


#endif //PALWORD_WISH_LECTEURCSV_H
