#pragma once
#include "Monster.h"

class FGoblin : public FMonster
{
public:
	FGoblin();
	virtual ~FGoblin();
	void Jump();
	virtual void Move() override;
};

