#pragma once
#include "Position.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();
	int GetHP();
	void SetHP(int NewHP);
protected:
	int HP;
	FPosition ActorPos;
	void Move(char key);
	void Attack();
	void Die();
};

