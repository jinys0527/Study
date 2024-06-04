#pragma once
#include "Monster.h"
class FGoblin : public FMonster
{
public:
	FGoblin();
	virtual ~FGoblin();
	FGoblin(int X, int Y);
	virtual void Move() override;
};

