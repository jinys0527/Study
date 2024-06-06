#pragma once
#include "Actor.h"
class FMonster : public AActor
{
public:
	FMonster();
	virtual ~FMonster();
	virtual void Move() override;
	virtual void Attack() override;
	virtual void AttackUp(AActor* Actor, int X, int Y) override;
	virtual void AttackLeft(AActor* Actor, int X, int Y) override;
	virtual void AttackDown(AActor* Actor, int X, int Y) override;
	virtual void AttackRight(AActor* Actor, int X, int Y) override;
protected:
	int CurDirection;
};

