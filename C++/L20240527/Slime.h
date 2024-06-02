#pragma once
#include "Monster.h"

class FSlime : public FMonster
{
public:
	FSlime();
	virtual ~FSlime();
	void Slide();
	virtual void Move() override;
};

