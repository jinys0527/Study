#pragma once
#include "Position.h"


class AActor
{
public:
	AActor();
	virtual ~AActor();
	int GetHP();
	void SetHP(int NewHP);
	bool GetFlag();
	void SetFlag(bool NewFlag);
	FPosition GetPos();
	virtual void Move();
	virtual void Move(char key);
	virtual void Attack();
	virtual void Attack(char key);

protected:
	int HP;
	FPosition ActorPos;
	bool DieFlag;
	void Die();
};

