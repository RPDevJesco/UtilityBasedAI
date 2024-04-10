#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "IUtilityCalculator.h"
#include "EnemyState.h"
// Include the headers for the specific utility calculators
#include "AttackUtilityCalculator.h"
#include "CoverUtilityCalculator.h"
#include "PursueUtilityCalculator.h"
#include "IdleUtilityCalculator.h"

namespace UtilityBasedAI
{
    class AIController
    {
    public:
        int Health;
        int DistanceToEnemy;
        EnemyState CurrentEnemyState;
        int SecondsSinceLastAttacked;

        AIController(int health, int distanceToEnemy, EnemyState enemyState, int secondsSinceLastAttacked);

        void EvaluateActions();
    };
}
