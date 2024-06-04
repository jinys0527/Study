#include "Player.h"
#include "Game.h"
#include <iostream>
using namespace std;

APlayer::APlayer()
{
	SetType(EType::Player);
	Name = "Player";
}

APlayer::~APlayer()
{
}

APlayer::APlayer(int X, int Y)
{
	GetPos().SetX(X);
	GetPos().SetY(Y);
	SetType(EType::Player);
	Name = "Player";
}

bool APlayer::GetAttackFlag()
{
	return AttackFlag;
}

void APlayer::SetAttackFlag(bool NewFlag)
{
	AttackFlag = NewFlag;
}

void APlayer::DetectEnemy(char key)
{
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (key)
	{
	case 'w':
		if (FGame::GetType(CurX, CurY - 1) == EType::Goblin ||
			FGame::GetType(CurX, CurY - 1) == EType::Boar || 
			FGame::GetType(CurX, CurY - 1) == EType::Slime)
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	case 'a':
		if (FGame::GetType(CurX - 1, CurY) == EType::Goblin ||
			FGame::GetType(CurX - 1, CurY) == EType::Boar ||
			FGame::GetType(CurX - 1, CurY) == EType::Slime)
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	case 's':
		if (FGame::GetType(CurX, CurY + 1) == EType::Goblin ||
			FGame::GetType(CurX, CurY + 1) == EType::Boar ||
			FGame::GetType(CurX, CurY + 1) == EType::Slime)
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	case 'd':
		if (FGame::GetType(CurX + 1, CurY) == EType::Goblin ||
			FGame::GetType(CurX + 1, CurY) == EType::Boar ||
			FGame::GetType(CurX + 1, CurY) == EType::Slime)
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	}
}

void APlayer::Move(char key)
{
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (key)
	{
	case 'w':
		if (FGame::GetType(CurX, CurY - 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX, CurY - 1);
			GetPos().SetY(CurY - 1);
		}
		break;
	case 'a':
		if (FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX - 1, CurY);
			GetPos().SetX(CurX - 1);
		}
		break;
	case 's':
		if (FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX, CurY + 1);
			GetPos().SetY(CurY + 1);
		}
		break;
	case 'd':
		if (FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX + 1, CurY);
			GetPos().SetX(CurX + 1);
		}
		break;
	default:
		break;
	}

	Direction = key;
}

void APlayer::Attack(char key)
{
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	DetectEnemy(key);

	if (AttackFlag == true)
	{	
		switch (key)
		{
		case 'w':
			for (AActor* Actor : FGame::GetActors())
			{
				if (Actor->GetPos().GetX() == CurX && Actor->GetPos().GetY() == CurY - 1)
				{
					if (Actor->GetHP() == 0)
					{
						Actor->Die();
					}
					else if (Actor->GetFlag())
					{
						FGame::SetType(EType::None, CurX, CurY - 1);
						delete Actor;
					}
					else
					{
						Actor->SetHP(Actor->GetHP() - 10);
						cout << Actor->GetName() << Actor->GetHP();
					}
				}
			}
			break;
		case 'a':
			for (AActor* Actor : FGame::GetActors())
			{
				if (Actor->GetPos().GetX() == CurX - 1 && Actor->GetPos().GetY() == CurY)
				{
					if (Actor->GetHP() == 0)
					{
						Actor->Die();
					}
					else if (Actor->GetFlag())
					{
						FGame::SetType(EType::None, CurX - 1, CurY);
						delete Actor;
					}
					else 
					{
						Actor->SetHP(Actor->GetHP() - 10);
						cout << Actor->GetName() << Actor->GetHP();
					}
				}
			}

			break;
		case 's':
			for (AActor* Actor : FGame::GetActors())
			{
				if (Actor->GetPos().GetX() == CurX && Actor->GetPos().GetY() == CurY + 1)
				{
					if (Actor->GetHP() == 0)
					{
						Actor->Die();
					}
					else if (Actor->GetFlag())
					{
						FGame::SetType(EType::None, CurX, CurY + 1);
						delete Actor;
					}
					else
					{
						Actor->SetHP(Actor->GetHP() - 10);
						cout << Actor->GetName() << Actor->GetHP();
					}
				}
			}

			break;
		case 'd':
			for (AActor* Actor : FGame::GetActors())
			{
				if (Actor->GetPos().GetX() == CurX + 1&& Actor->GetPos().GetY() == CurY)
				{
					if (Actor->GetHP() == 0)
					{
						Actor->Die();
					}
					else if (Actor->GetFlag())
					{
						FGame::SetType(EType::None, CurX + 1, CurY);
						delete Actor;
					}
					else
					{
						Actor->SetHP(Actor->GetHP() - 10);
						cout << Actor->GetName() << Actor->GetHP();
					}
				}
			}

			break;
		}

	}
}
