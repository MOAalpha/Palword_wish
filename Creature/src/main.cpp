#include <iostream>
#include <thread>

#include "../inc/Moacreature.h"
#include "../inc/Collections_Moacreature.h"
#include "../../Render/Inc/GUI.h"
#include "../inc/MoaDex.h"
#include "../inc/mon_MoaDex.h"
#include "../../Ressources/Ressources.h"
#include "../../Engine/Inc/Welcome.h"
#include "../inc/tests_creature.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
/**
 * Ce main est actuellement un ensemble de tests dont les resultats sont visibles dans la console
 * @return
 */
int main() {

    auto tests = false; //active les tests
    if (tests) {
        auto test_unitaire = new tests_creature();
        test_unitaire->test_all();
    }

    //Activation du moteur de jeu
    auto* gameEngine = new GameEngine();
    gameEngine->run();

    return 0;
}
