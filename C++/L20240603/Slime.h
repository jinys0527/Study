#pragma once
#include "Monster.h"
class FSlime : public FMonster
{
public:
	FSlime();
	virtual ~FSlime();
	FSlime(int X, int Y);
	virtual void Move() override;
};

