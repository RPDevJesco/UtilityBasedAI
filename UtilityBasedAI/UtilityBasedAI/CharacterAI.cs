namespace UtilityBasedAI
{
    public class CharacterAI
    {
        public int Health { get; set; }
        public int DistanceToEnemy { get; set; }
        public EnemyState EnemyState { get; set; }
        public int SecondsSinceLastAttacked { get; set; }

        public CharacterAI(int health, int distanceToEnemy, EnemyState enemyState, int secondsSinceLastAttacked)
        {
            Health = health;
            DistanceToEnemy = distanceToEnemy;
            EnemyState = enemyState;
            SecondsSinceLastAttacked = secondsSinceLastAttacked;

            // Check if the enemy should be in the Idle state based on the given rules
            if (SecondsSinceLastAttacked > 10 && DistanceToEnemy > 100)
            {
                EnemyState = EnemyState.Idle;
            }
        }

        public void EvaluateActions()
        {
            var calculators = new List<(IUtilityCalculator calculator, string action)>
            {
                (new AttackUtilityCalculator(), "Attacking"),
                (new CoverUtilityCalculator(), "Taking Cover"),
                (new PursueUtilityCalculator(), "Pursuing Enemy"),
                (new IdleUtilityCalculator(), "Going Idle")
            };

            var utilities = calculators.Select(c => (utility: c.calculator.CalculateUtility(this), action: c.action)).ToList();
            var maxUtilityAction = utilities.Aggregate((max, current) => (max.utility > current.utility) ? max : current);

            Console.WriteLine($"{maxUtilityAction.action}: Utility = {maxUtilityAction.utility}");
        }
    }
}