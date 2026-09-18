//
// Created by mathe on 14/09/2026.
//

#ifndef PALWORD_WISH_LISTE_PERSONNELLE_MOACREATURE_H
#define PALWORD_WISH_LISTE_PERSONNELLE_MOACREATURE_H
#include "Collections_Moacreature.h"
#include <vector>

#include "MoaDex.h"
#include "../Ressources/Ressources.h"

class mon_MoaDex : public Collections_Moacreature {
private:
    MoaDex* dico = MoaDex::get_instance(MOADEX_FILE);
public:
    mon_MoaDex()= default;
    void obtenir_creature(string nom_de_moacreature);
    void supprimer_creature(string nom_de_moacreature);
    Moacreature* chercher_moacreature(string nom_de_moacreature) override;
    Moacreature* chercher_moacreature(int id) override;
    int regenerer_moacreature(string nom_de_moacreature);


};


#endif //PALWORD_WISH_LISTE_PERSONNELLE_MOACREATURE_H
