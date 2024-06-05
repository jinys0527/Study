#pragma once
#include <string>
#include "Position.h"

enum class EType
{
	None = -1,
	Wall,
	Player,
	Goblin,
	Slime,
	Boar,
	EndPoint,
	Max
};

class AActor
{
public:
	AActor();
	virtual ~AActor();
	int GetHP();
	void SetHP(int NewHP);
	bool GetFlag();
	void SetFlag(bool NewFlag);
	EType GetType();
	void PrintType();
	void SetType(EType NewType);
	FPosition& GetPos();
	virtual bool GetArriveFlag();
	virtual void Move();
	virtual void Move(char key);
	virtual void Attack();
	virtual void Attack(char key);
	virtual void PrintMove(char key);
	virtual void PrintAttack(char key);
	virtual std::string GetName();
	virtual void Die();
protected:
	EType Type;
	std::string Name;
	int HP;
	FPosition ActorPos;
	bool DieFlag;
};

