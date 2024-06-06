#include "Monster.h"
#include "Game.h"
#include "Player.h"
#include "Util.h"

FMonster::FMonster()
{
	CurDirection = 3;
}

FMonster::~FMonster()
{
}

void FMonster::Move()
{
	
}

void FMonster::Attack()
{  
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	int num = rand() % 4 + 1;
	CurDirection = num;
	switch (num)
	{
	case 1:			//W
		if (FGame::GetType(CurX, CurY - 1) == EType::Player)
		{
			for (AActor* Actor : FGame::GetActors())
			{
				AttackUp(Actor, CurX, CurY);
			}
		}
		PrintType();
		cout << " Attack Up" << endl;
		break;
	case 2:			//A
		if (FGame::GetType(CurX - 1, CurY) == EType::Player)
		{
			for (AActor* Actor : FGame::GetActors())
			{
				AttackLeft(Actor, CurX, CurY);
			}
		}
		PrintType();
		cout << " Attack Left" << endl;
		break;
	case 3:			//S
		if (FGame::GetType(CurX, CurY + 1) == EType::Player)
		{
			for (AActor* Actor : FGame::GetActors())
			{
				AttackDown(Actor, CurX, CurY);
			}
		}
		PrintType();
		cout << " Attack Down" << endl;
		break;
	case 4:			//D
		if (FGame::GetType(CurX + 1, CurY) == EType::Player)
		{
			for (AActor* Actor : FGame::GetActors())
			{
				AttackRight(Actor, CurX, CurY);
			}
		}
		PrintType();
		cout << " Attack Right" << endl;
		break;
	default:
		break;
	}
}

void FMonster::AttackUp(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X && Actor->GetPos().GetY() == Y - 1)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X, Y - 1);
			Actor->SetFlag(true);
		}
	}
}

void FMonster::AttackLeft(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X - 1 && Actor->GetPos().GetY() == Y)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X - 1, Y);
			Actor->SetFlag(true);
		}
	}
}

void FMonster::AttackDown(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X && Actor->GetPos().GetY() == Y + 1)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X, Y + 1);
			Actor->SetFlag(true);
		}
	}
}

void FMonster::AttackRight(AActor* Actor, int X, int Y)
{
	if (Actor->GetPos().GetX() == X + 1 && Actor->GetPos().GetY() == Y)
	{
		Actor->SetHP(Actor->GetHP() - 10);
		cout << Actor->GetName() << " : " << Actor->GetHP() << endl;
		if (Actor->GetHP() == 0)
		{
			FGame::DestroyActor(Actor, X + 1, Y);
			Actor->SetFlag(true);
		}
	}
}
