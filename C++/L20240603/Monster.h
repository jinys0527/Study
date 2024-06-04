#pragma once
#include "Actor.h"
class FMonster : public AActor
{
public:
	FMonster();
	virtual ~FMonster();
	virtual void Move() override;
	virtual void Attack() override;
protected:
	FPosition MonsterPos;
	int CurDirection;
	
};

