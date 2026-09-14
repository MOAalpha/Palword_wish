//
// Created by mathe on 10/09/2026.
//

#ifndef PALWORD_WISH_Moacreature_H
#define PALWORD_WISH_Moacreature_H
#include <string>
using namespace std;

/**
 *  cf. Livre de référence CLEAN CODE
 *
 * La classe Moacreature permet de définir un Moacreature par :
 * - un identifiant
 * - un nom
 * - des points d'attaque, de défense, et de points de vie
 *
 *
 */
class Moacreature {
private:
    int id;
    string name;
    double attack;
    double defense;
    int generation;
    double hitPoint;


public:
    static int total_Moacreature; //pas bien, variable global

    //Constructeur
    Moacreature(int id, string name, double hitPoint, double attack, double defense, int generation );

    Moacreature()=delete;
    ~Moacreature();

    Moacreature(string name, int generation);
    Moacreature(const Moacreature& autre_Moacreature);

    void displayInfo() const;
    int getId() const;
    string getName() const;
    double getHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    double getGeneration() const;
    int getTotalCreature() const;

    void setHitPoint(double hitPoint);

    void attaque_simple(Moacreature& cible);
    void total_creature();

};


#endif //PALWORD_WISH_Moacreature_H
