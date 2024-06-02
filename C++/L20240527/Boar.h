#pragma once
#include "Monster.h"

class FBoar : public FMonster
{
public:
	FBoar();
	virtual ~FBoar();
	void Run();
	virtual void Move() override;
};

