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
    virtual int trouver_la_creature(int id);
    virtual int trouver_la_creature(std::string name);
    virtual ~Collections_Moacreature();
    void lister_creature();
    void obtient(Moacreature* moa);
};


#endif //PALWORD_WISH_COLLECTIONS_MOACREATURE_H
