#include <iostream>
#include "AIController.h"

using namespace UtilityBasedAI;

int main() {
    AIController* ai = new AIController(80, 120, EnemyState::Retreating, 8);
    ai->EvaluateActions();
    delete ai;
    return 0;
}