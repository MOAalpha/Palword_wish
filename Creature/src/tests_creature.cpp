//
// Created by belou on 04/10/2026.
//

#include "../inc/tests_creature.h"

#include <assert.h>

#include "../inc/moadex.h"
#include "../inc/mon_MoaDex.h"

 //Collection de creature

tests_creature::tests_creature() {
    troupeau_de_moa = new mon_MoaDex();
}

void tests_creature::test_all() {
    attaque_dans_une_collection();
    attaque_moacreature_qui_marche();
    attaque_moacreature_qui_echoue();
    ajout_creature();
    supprimer_creature();
    test_Singleton();
}

/**
 * teste l'attaque dans une collection de moacreatures.
 */
void tests_creature::attaque_dans_une_collection() {
    std::cout << "C'est l'heure du DUUDUDUDUEL !!!" <<std::endl;
    Moacreature* mon_Fearow = troupeau_de_moa->chercher_moacreature("Fearow");
    Moacreature* mon_Charizard = troupeau_de_moa->chercher_moacreature("Charizard");
    if (mon_Charizard == nullptr || mon_Fearow == nullptr) {
        std::cout << "JSP QUOI METTRE ..." <<std::endl;
        return;
    }
    mon_Fearow->displayInfo();
    mon_Charizard->displayInfo();
    for (int i = 0; i < 7; i++) {
        mon_Fearow->attaque_simple(*mon_Charizard);
    }
    Moacreature* Fearow2 = troupeau_de_moa->chercher_moacreature("Fearow");
    Fearow2->displayInfo();
    Moacreature* Charizard2 = troupeau_de_moa->chercher_moacreature("Charizard");
    Charizard2->displayInfo();
}

/**
 * Teste si une creature peut en attaquer une autre, l'attaque correspondant à attaque de l'attaquant - défense de la cible
 * si l'attaque est supérieure à la défense de la cible, sinon l"attaque n'a aucun effet.
 * L'attaque doit marcher ici.
 */
void tests_creature::attaque_moacreature_qui_marche() {
    //Premier Moacreature
    auto test = Moacreature(4012, "Patrick", 10, 100, 1, 9 );
    //test.displayInfo();


    // Deuxieme Moacreature
    auto test3 = Moacreature (6789, "Bob", 10, 10, 75, 12 );
    //test3.displayInfo();

    //TEST ATTAQUE qui marche
    test.attaque_simple(test3);
    assert(test3.getHitPoint() == 1);
}

/**
 * Teste si une creature peut en attaquer une autre, l'attaque correspondant à attaque de l'attaquant - défense de la cible
 * si l'attaque est supérieure à la défense de la cible, sinon l"attaque n'a aucun effet.
 * L'attaque doit "échouer" ici.
 */
void tests_creature::attaque_moacreature_qui_echoue(){

    auto attaquant_B = Moacreature (1976, "Shakira", 100, 100, 75, 1 );
    auto cible_B = Moacreature (1977, "Pique", 100, 100, 105, 1 );
    attaquant_B.attaque_simple(cible_B);
    assert(attaquant_B.getHitPoint() == 100);

}

/**
 * Teste le Moadex d'un joueur, qui ne peut ajouter des créatures uniquement si elles font parties du Moadex global.
 */
void tests_creature::ajout_creature() {
    troupeau_de_moa->obtenir_creature("Fearow");
    troupeau_de_moa->obtenir_creature("Charizard");
    troupeau_de_moa->lister_creature();
    assert(troupeau_de_moa->trouver_la_creature("Fearow") == 0);
    assert(troupeau_de_moa->trouver_la_creature("Charizard") == 0);
}

void tests_creature::supprimer_creature() {
    // Test ajout/retrait d'une collection de creatures. Machine
    troupeau_de_moa->obtenir_creature("Fearow");
    troupeau_de_moa->obtenir_creature("Metapod");
    assert(troupeau_de_moa->trouver_la_creature("Metapod") == 0);
    troupeau_de_moa->supprimer_creature("Metapod");
    assert(troupeau_de_moa->trouver_la_creature("Metapod") == -1);
    assert(troupeau_de_moa->trouver_la_creature("Fearow") == 0);

}

/**
 * teste s'il y a bien une unique instance sur le Moadex global
 */
void tests_creature::test_Singleton() {
    MoaDex* mon_troupeau = MoaDex::get_instance(MOADEX_FILE); //ficher de base

    //Utilisation d'un mauvais fichier, si pas de message d'erreur, alors les 2 autres font bien référence à mon_troupeau
    MoaDex* test_singleton = MoaDex::get_instance("Louche");
    MoaDex* autre_test = MoaDex::get_instance("kglsfghfdjkhgdk");
    //mon_troupeau, test_singleton, autre_test pointent vers la meme reference, meme si le fichier est différent
    // ie aucune nouvelle instance n'est créé

    assert(autre_test == test_singleton);
    assert(autre_test->trouver_la_creature(5) == test_singleton->trouver_la_creature(5));
}

/**
 * Teste est-ce que toutes les instances de mon_MoaDex pointe bien vers le meme dico
 */
void tests_creature::test_Moadex() {

    mon_MoaDex Android = mon_MoaDex();
    mon_MoaDex Android2 = mon_MoaDex();
    assert(Android.chercher_moacreature(56) == Android2.chercher_moacreature(56));
}

