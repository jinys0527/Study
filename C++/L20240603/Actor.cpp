#include "Actor.h"
#include "Util.h"

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

void AActor::PrintType()
{
	switch(GetType())
	{
	case EType::None:
		cout << "None";
		break;
	case EType::Wall:
		cout << "Wall";
		break;
	case EType::Player:
		cout << "Player";
		break;
	case EType::EndPoint:
		cout << "EndPoint";
		break;
	case EType::Goblin:
		cout << "Goblin";
		break;
	case EType::Boar:
		cout << "Boar";
		break;
	case EType::Slime:
		cout << "Slime";
		break;
	default:
		break;
	}
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

void AActor::PrintMove(char key)
{
}

void AActor::PrintAttack(char key)
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
