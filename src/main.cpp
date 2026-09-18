#include <iostream>

#include "../inc/Moacreature.h"
#include "../inc/Collections_Moacreature.h"
#include "../inc/GUI.h"
#include "../inc/MoaDex.h"
#include "../inc/mon_MoaDex.h"
#include "../Ressources/Ressources.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
/**
 * Ce main est actuellement un ensemble de tests dont les resultats sont visibles dans la console
 * @return
 */
int main() {

    //Collection de creature
    auto troupeau_de_moa = new mon_MoaDex();

    //Premier Moacreature
    auto test = Moacreature(4012, "Patrick", 10, 100, 1, 9 );
    test.displayInfo();
    troupeau_de_moa->obtenir_creature("Fearow");

    // Deuxieme Moacreature
    auto test3 = Moacreature (6789, "Bob", 10, 10, 75, 12 );
    test3.displayInfo();
    troupeau_de_moa->obtenir_creature("Charizard");
    troupeau_de_moa->lister_creature();


    //TEST ATTAQUE
    test.attaque_simple(test3);

    //Test Singleton :
    //Collections_Moacreature troupeau_de_moa;
    MoaDex* mon_troupeau = MoaDex::get_instance(MOADEX_FILE);
    MoaDex* test_singleton = MoaDex::get_instance("Louche");
    MoaDex* autre_test = MoaDex::get_instance("kglsfghfdjkhgdk");
    //mon_troupeau, test_singleton, autre_test pointent vers la meme reference, meme si le fichier est différent
    // ie aucune nouvelle instance n'est créé

    // Test ajout/retrait d'une collection de creatures. Machine
    //autre_test->lister_creature();
    troupeau_de_moa->obtenir_creature("Metapod");
    troupeau_de_moa->lister_creature();
    std::cout << "C'est l'heure du DUUDUDUDUEL !!!" <<std::endl;
    Moacreature* mon_Fearow = troupeau_de_moa->chercher_moacreature("Fearow");
    Moacreature* mon_Charizard = troupeau_de_moa->chercher_moacreature("Charizard");
    if (mon_Charizard == nullptr || mon_Fearow == nullptr) {
        std::cout << "JSP QUOI METTRE ..." <<std::endl;
        return 1;
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

    troupeau_de_moa->supprimer_creature("Fearow");

    Moacreature* Metapod2 = troupeau_de_moa->chercher_moacreature("Metapod");
    if (Metapod2 == nullptr) {
        std::cout << "Ce n'est plus dans la collection" << std::endl;
    }else {
        Metapod2->displayInfo();
    }
    troupeau_de_moa->lister_creature();
    //Test est ce que toutes les instances de mon_MoaDex pointe bien vers le meme dico
    mon_MoaDex Android = mon_MoaDex();
    mon_MoaDex Android2 = mon_MoaDex();

    GUI interface_graphique = GUI();
    interface_graphique.afficher_fond();


    return 0;
}
