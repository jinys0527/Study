#include "Actor.h"
#include "Util.h"
#include "Game.h"

bool AActor::DieFlag;
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

void AActor::MoveUp(EType Type, int X, int Y)
{
	FGame::SetType(EType::None, X, Y);
	Y--;
	FGame::SetType(Type, X, Y);
	GetPos().SetY(Y);
}

void AActor::MoveLeft(EType Type, int X, int Y)
{
	FGame::SetType(EType::None, X, Y);
	X--;
	FGame::SetType(Type, X, Y);
	GetPos().SetX(X);
}

void AActor::MoveDown(EType Type, int X, int Y)
{
	FGame::SetType(EType::None, X, Y);
	Y++;
	FGame::SetType(Type, X, Y);
	GetPos().SetY(Y);
}

void AActor::MoveRight(EType Type, int X, int Y)
{
	FGame::SetType(EType::None, X, Y);
	X++;
	FGame::SetType(Type, X, Y);
	GetPos().SetX(X);
}



void AActor::Attack()
{
}

void AActor::Attack(char key)
{
}

void AActor::AttackUp(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X && Actor->GetPos().GetY() == Y - 1)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X, Y - 1);
		}
	}
}

void AActor::AttackLeft(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X - 1 && Actor->GetPos().GetY() == Y)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X - 1, Y);
		}
	}
}

void AActor::AttackDown(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X && Actor->GetPos().GetY() == Y + 1)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X, Y + 1);
		}
	}
}

void AActor::AttackRight(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X + 1 && Actor->GetPos().GetY() == Y)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X + 1, Y);
		}
	}
}

bool AActor::IsMonster(int X, int Y)
{
	if (FGame::GetType(X, Y) == EType::Goblin ||
		FGame::GetType(X, Y) == EType::Boar ||
		FGame::GetType(X, Y) == EType::Slime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AActor::CanMove(int X, int Y)
{
	if (FGame::GetType(X, Y) == EType::None)
	{
		return true;
	}
	else
	{
		return false;
	}
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
