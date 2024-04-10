namespace UtilityBasedAI
{
    public class IdleUtilityCalculator : IUtilityCalculator
    {
        public float CalculateUtility(CharacterAI character)
        {
            // The utility for being idle could be based on the character's health and the distance to the enemy
            // For example, higher utility for being idle when the character has high health and the enemy is far away
            return character.Health * 0.5f + (200 - character.DistanceToEnemy) * 0.1f;
        }
    }
}