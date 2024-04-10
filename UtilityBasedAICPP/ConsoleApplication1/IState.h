#pragma once

class IState
{
public:
	virtual void Enter() = 0;
	virtual void Execute() = 0;
	virtual void Exit() = 0;
};