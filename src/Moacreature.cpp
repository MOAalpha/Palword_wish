//
// Created by mathe on 10/09/2026.
//

#include "../inc/Moacreature.h"
#include <iostream>

using namespace std;

int Moacreature::total_Moacreature = 0; //juste l'initialisation, pas une variable globale.

Moacreature::Moacreature(int id, string name, double hitPoint, double attack, double defense, int generation):
id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense), generation(generation) {total_Moacreature++;}

Moacreature::Moacreature(string name, int generation) : name(name), generation(generation) {total_Moacreature++;}

Moacreature::Moacreature(const Moacreature& autre_Moacreature): name(autre_Moacreature.name), generation(autre_Moacreature.generation), id(autre_Moacreature.id),hitPoint(1),attack(1),defense(1)
{ std::cout << "Moacreature " << name << " copie "<< std::endl; };

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
double Moacreature::getGeneration() const {
    return Moacreature::generation;
}

double Moacreature::getHitPoint() const {
    return Moacreature::hitPoint;
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

void Moacreature::attaque_simple(Moacreature &cible) {
    if (getAttack()>cible.getDefense()) {
        cible.setHitPoint(cible.getHitPoint() -(getAttack()-cible.getDefense()));
    }
    if (cible.getHitPoint() <= 0) {
        std::cout << "Cible " << cible.name << " eliminee ! Mission echouee ! (Maltraitance animale...) ";
        std::cout << std::endl;
    }
}

void Moacreature::total_creature() {
    std::cout << "Il y a " << total_Moacreature << " moacreature." << std::endl;
}



