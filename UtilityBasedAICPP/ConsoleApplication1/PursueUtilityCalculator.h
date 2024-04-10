#pragma once
#include "IUtilityCalculator.h" // Include the interface definition
#include "AIController.h" // Include the AIController class definition

namespace UtilityBasedAI
{
    class PursueUtilityCalculator : public IUtilityCalculator
    {
    public:
        float CalculateUtility(AIController* character) override;
    };
}