using UtilityBasedAI;

namespace UtilityBasedAIUsage
{
    class Program
    {
        static void Main(string[] args)
        {
            CharacterAI ai = new CharacterAI(80, 120, EnemyState.Retreating, 8);
            ai.EvaluateActions();
        }
    }
}