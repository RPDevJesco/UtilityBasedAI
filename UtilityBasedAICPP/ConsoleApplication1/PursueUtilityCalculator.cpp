#include "PursueUtilityCalculator.h"

namespace UtilityBasedAI
{
    float PursueUtilityCalculator::CalculateUtility(AIController* character)
    {
        switch (character->CurrentEnemyState)
        {
        case EnemyState::Idle:
            return (100 - character->DistanceToEnemy) * 0.1f + (100 - character->Health) * 0.1f;
        case EnemyState::Aggressive:
            return character->DistanceToEnemy * 0.5f + (100 - character->Health);
        case EnemyState::CallingForBackup:
            return character->DistanceToEnemy + (100 - character->Health) * 0.5f;
        case EnemyState::Retreating:
            return character->DistanceToEnemy * 1.5f + (100 - character->Health);
        default:
            return 0;
        }
    }
}