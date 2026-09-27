//
// Created by mathe on 10/09/2026.
//

#include "../inc/Moacreature.h"
#include <iostream>

using namespace std;

int Moacreature::total_Moacreature = 0; //juste l'initialisation, pas une variable globale.

Moacreature::Moacreature(int id, string name, double hitPointMax, double attack, double defense, int generation):
id(id), name(name), hitPoint(hitPointMax), hitPointMax(hitPointMax), attack(attack), defense(defense), generation(generation) {total_Moacreature++;}

Moacreature::Moacreature(const Moacreature& autre_Moacreature): name(autre_Moacreature.getName()), generation(autre_Moacreature.getGeneration()), id(autre_Moacreature.getId()),hitPoint(autre_Moacreature.getHitPoint()), hitPointMax(autre_Moacreature.hitPointMax), attack(autre_Moacreature.getAttack()),defense(autre_Moacreature.getDefense())
{};

Moacreature::~Moacreature() {
    cout << "Activation du destructeur en cours !" << endl;
    total_Moacreature--;
}

void Moacreature::displayInfo() const {
    cout << "Voici le Moacreature " << id << " : " << name << endl;
    cout << "Points de vie : " << hitPoint<<endl;
    cout << "Attaque : " << attack << endl;
    cout << "Defense : " << defense << endl;
    cout << "Membre de la generation "<< generation <<   endl;
    cout << endl;
}

int Moacreature::getId() const {
    return Moacreature::id;
}
double Moacreature::getAttack() const {
    return Moacreature::attack;
}

double Moacreature::getDefense() const {
    return Moacreature::defense;
}
int Moacreature::getGeneration() const {
    return Moacreature::generation;
}

double Moacreature::getHitPoint() const {
    return Moacreature::hitPoint;
}

double Moacreature::getHitPointMax() const {
    return Moacreature::hitPointMax;
}

string Moacreature::getName() const {
    return Moacreature::name;
}

int Moacreature::getTotalCreature() const {
    return Moacreature::total_Moacreature;
}

void Moacreature::setHitPoint(double nouveau_hitPoint) {
    Moacreature::hitPoint = nouveau_hitPoint;
}

/**
* Attaque la créature cible si l'attaque est supérieure à la défense de la cible.
 * @param cible
 * @return 0 si l'attaque a été encaissée, 1 si l'attaque a tué la creature.
 */
int Moacreature::attaque_simple(Moacreature &cible) {
    if (getAttack()>cible.getDefense()) {
        std::cout << std::endl;
        std::cout << "Attaque de " << cible.getName() << " par " << this->getName() <<" de degats " <<this->getAttack()-cible.getDefense() << std::endl;
        std::cout << std::endl;
        cible.setHitPoint(cible.getHitPoint() -(getAttack()-cible.getDefense()));
    }
    if (cible.getHitPoint() <= 0) {
        std::cout << "Cible " << cible.name << " eliminee ! Mission echouee ! (Maltraitance animale...) ";
        std::cout << std::endl;
        cible.setHitPoint(1);
        return 1;
    }
    return 0;
}

void Moacreature::total_creature() {
    std::cout << "Il y a " << total_Moacreature << " moacreature." << std::endl;
}



