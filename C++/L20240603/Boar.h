#pragma once
#include "Monster.h"
class FBoar : public FMonster
{
public:
	FBoar();
	virtual ~FBoar();
	FBoar(int X, int Y);
	virtual void Move() override;
};

