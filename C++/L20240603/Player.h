#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();
	APlayer(int X, int Y);
	bool GetAttackFlag();
	void SetAttackFlag(bool NewFlag);
	virtual void Move(char key) override;
	virtual void Attack(char key) override;
	void DetectEnemy(char key);
protected:
	char Direction = 'd';
	bool AttackFlag = false;
	
};

