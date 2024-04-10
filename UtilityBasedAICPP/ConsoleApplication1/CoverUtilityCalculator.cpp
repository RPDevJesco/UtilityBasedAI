#include "CoverUtilityCalculator.h"

namespace UtilityBasedAI
{
    float CoverUtilityCalculator::CalculateUtility(AIController* character)
    {
        switch (character->CurrentEnemyState)
        {
        case EnemyState::Idle:
            return (100 - character->Health) * 0.1f;
        case EnemyState::Aggressive:
            return character->DistanceToEnemy + (100 - character->Health);
        case EnemyState::CallingForBackup:
            return (100 - character->DistanceToEnemy) + (100 - character->Health) * 1.5f;
        case EnemyState::Retreating:
            return (100 - character->DistanceToEnemy) + (100 - character->Health) * 0.5f;
        default:
            return 0;
        }
    }
}