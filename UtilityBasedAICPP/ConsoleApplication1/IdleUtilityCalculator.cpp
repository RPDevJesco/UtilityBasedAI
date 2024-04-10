#include "IdleUtilityCalculator.h"

namespace UtilityBasedAI
{
    float IdleUtilityCalculator::CalculateUtility(AIController* character)
    {
        return character->Health * 0.5f + (200 - character->DistanceToEnemy) * 0.1f;
    }
}