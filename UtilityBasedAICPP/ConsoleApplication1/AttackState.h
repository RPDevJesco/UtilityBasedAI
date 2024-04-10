#pragma once
#include "IState.h"
class AttackState : public IState
{
	void Enter() override;
	void Execute() override;
	void Exit() override;
};