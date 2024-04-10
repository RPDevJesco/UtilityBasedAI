namespace UtilityBasedAI
{
    public class CoverUtilityCalculator : IUtilityCalculator
    {
        public float CalculateUtility(CharacterAI character)
        {
            switch (character.EnemyState)
            {
                case EnemyState.Idle:
                    return (100 - character.Health) * 0.1f;
                case EnemyState.Aggressive:
                    return character.DistanceToEnemy + (100 - character.Health);
                case EnemyState.CallingForBackup:
                    return character.DistanceToEnemy + (100 - character.Health) * 1.5f;
                case EnemyState.Retreating:
                    return character.DistanceToEnemy + (100 - character.Health) * 0.5f;
                default:
                    return 0;
            }
        }
    }
}