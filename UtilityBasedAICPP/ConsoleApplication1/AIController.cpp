#include "AIController.h"

namespace UtilityBasedAI
{
    AIController::AIController(int health, int distanceToEnemy, EnemyState enemyState, int secondsSinceLastAttacked)
        : Health(health), DistanceToEnemy(distanceToEnemy), CurrentEnemyState(enemyState), SecondsSinceLastAttacked(secondsSinceLastAttacked)
    {
        if (SecondsSinceLastAttacked > 10 && DistanceToEnemy > 100)
        {
            this->CurrentEnemyState = EnemyState::Idle;
        }
    }

    void AIController::EvaluateActions()
    {
        std::vector<std::pair<IUtilityCalculator*, std::string>> calculators = {
            {new AttackUtilityCalculator(), "Attacking"},
            {new CoverUtilityCalculator(), "Taking Cover"},
            {new PursueUtilityCalculator(), "Pursuing Enemy"},
            {new IdleUtilityCalculator(), "Going Idle"}
        };

        std::vector<std::pair<float, std::string>> utilities;
        for (auto& calc : calculators)
        {
            utilities.push_back({ calc.first->CalculateUtility(this), calc.second });
        }

        auto maxUtilityAction = *std::max_element(utilities.begin(), utilities.end(),
            [](const std::pair<float, std::string>& a, const std::pair<float, std::string>& b) {
                return a.first < b.first;
            });

        std::cout << maxUtilityAction.second << ": Utility = " << maxUtilityAction.first << std::endl;

        for (auto& calc : calculators)
        {
            delete calc.first;
        }
    }
}