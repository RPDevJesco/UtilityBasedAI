#pragma once
namespace UtilityBasedAI
{
    // Forward declaration of CharacterAI to resolve circular dependency.
    class AIController;

    class IUtilityCalculator
    {
    public:
        // Virtual destructor for proper cleanup of derived classes.
        virtual ~IUtilityCalculator() {}

        // Pure virtual function making this class an abstract class.
        virtual float CalculateUtility(AIController* character) = 0;
    };
}