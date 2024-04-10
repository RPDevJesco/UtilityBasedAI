namespace UtilityBasedAI
{
    public class AttackUtilityCalculator : IUtilityCalculator
    {
        public float CalculateUtility(CharacterAI character)
        {
            switch (character.EnemyState)
            {
                case EnemyState.Idle:
                    return (100 - character.DistanceToEnemy) * 0.1f + character.Health * 0.1f;
                case EnemyState.Aggressive:
                    return (100 - character.DistanceToEnemy) + character.Health;
                case EnemyState.CallingForBackup:
                    return (100 - character.DistanceToEnemy) + character.Health * 0.5f;
                case EnemyState.Retreating:
                    return (100 - character.DistanceToEnemy) + character.Health * 1.5f;
                default:
                    return 0;
            }
        }
    }
}