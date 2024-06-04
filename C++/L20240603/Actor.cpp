#include "Actor.h"
#include <string>

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

EType AActor::GetType()
{
	return Type;
}

void AActor::SetType(EType NewType)
{
	Type = NewType;
}

FPosition& AActor::GetPos()
{
	return ActorPos;
}

bool AActor::GetArriveFlag()
{
	return false;
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

std::string AActor::GetName()
{
	return Name;
}

void AActor::Die()
{
	DieFlag = true;
}
