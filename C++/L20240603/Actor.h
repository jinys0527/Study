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
	static bool GetFlag();
	static void SetFlag(bool NewFlag);
	EType GetType();
	void PrintType();
	void SetType(EType NewType);
	FPosition& GetPos();
	virtual bool GetArriveFlag();
	virtual void Move();
	virtual void Move(char key);
	virtual void MoveUp(EType Type, int X, int Y);
	virtual void MoveLeft(EType Type, int X, int Y);
	virtual void MoveDown(EType Type, int X, int Y);
	virtual void MoveRight(EType Type, int X, int Y);
	virtual void Attack();
	virtual void Attack(char key);
	virtual void AttackUp(AActor* Actor, int X, int Y);
	virtual void AttackLeft(AActor* Actor, int X, int Y);
	virtual void AttackDown(AActor* Actor, int X, int Y);
	virtual void AttackRight(AActor* Actor, int X, int Y);
	bool IsMonster(int X, int Y);
	bool CanMove(int X, int Y);
	virtual void PrintMove(char key);
	virtual void PrintAttack(char key);
	virtual std::string GetName();
	virtual void Die();
protected:
	EType Type;
	std::string Name;
	int HP;
	FPosition ActorPos;
	static bool DieFlag;
};

