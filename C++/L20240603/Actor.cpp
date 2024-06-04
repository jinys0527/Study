#include "Actor.h"

AActor::AActor()
{
	HP = 100;
	DieFlag = false;
}

AActor::~AActor()
{
}

int AActor::GetHP()
{
	return HP;
}

void AActor::SetHP(int NewHP)
{
	HP = NewHP;
}

bool AActor::GetFlag()
{
	return DieFlag;
}

void AActor::SetFlag(bool NewFlag)
{
	DieFlag = NewFlag;
}

FPosition AActor::GetPos()
{
	return ActorPos;
}

void AActor::Move()
{
}

void AActor::Move(char key)
{
}

void AActor::Attack()
{
}

void AActor::Attack(char key)
{
}

void AActor::Die()
{
	if (HP == 0)
	{
		DieFlag = true;
	}
}
