//
// Created by mathe on 11/09/2026.
//

#ifndef PALWORD_WISH_COLLECTIONS_MOACREATURE_H
#define PALWORD_WISH_COLLECTIONS_MOACREATURE_H

#include <vector>
#include "Moacreature.h"

class Collections_Moacreature {
protected:
    std::vector<Moacreature*> collection;
public:
    virtual Moacreature* chercher_moacreature(int id)=0;
    virtual Moacreature* chercher_moacreature(std::string nom_de_creature)=0;
    virtual ~Collections_Moacreature();
    void lister_creature();
    void obtient(Moacreature* moa);
    void perd(Moacreature* moa);

    virtual int trouver_la_creature(int id);
    virtual int trouver_la_creature(std::string nom_de_creature);
};


#endif //PALWORD_WISH_COLLECTIONS_MOACREATURE_H
