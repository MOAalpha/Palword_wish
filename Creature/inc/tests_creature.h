//
// Created by belou on 04/10/2026.
//

#ifndef PALWORD_WISH_TESTS_CREATURE_H
#define PALWORD_WISH_TESTS_CREATURE_H
#include "mon_MoaDex.h"


class tests_creature {
private:
    mon_MoaDex* troupeau_de_moa;
public:
    tests_creature();
    void test_all();
    void attaque_dans_une_collection();
    void attaque_moacreature_qui_marche();
    void attaque_moacreature_qui_echoue();
    void ajout_creature();
    void supprimer_creature();
    void test_Singleton();
    void test_Moadex();
};


#endif //PALWORD_WISH_TESTS_CREATURE_H
