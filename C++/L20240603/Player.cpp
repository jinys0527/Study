#include "Player.h"
#include "Game.h"
#include "Util.h"

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

bool APlayer::IsArrive(int X, int Y)
{
	if (FGame::GetType(X, Y) == EType::EndPoint)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool APlayer::GetArriveFlag()
{
	return ArriveFlag;
}

void APlayer::SetArriveFlag(bool NewFlag)
{
	ArriveFlag = NewFlag;
}

void APlayer::PrintMove(char key)
{
	switch (key)
	{
	case 'w':
		cout << "Player Move Up" << endl;
		break;
	case 'a':
		cout << "Player Move Left" << endl;
		break;
	case 's':
		cout << "Player Move Down" << endl;
		break;
	case 'd':
		cout << "Player Move Right" << endl;
		break;
	default:
		break;
	}
}

void APlayer::PrintAttack(char key)
{
	switch (key)
	{
	case 'w':
		cout << "Player Attack Up" << endl;
		break;
	case 'a':
		cout << "Player Attack Left" << endl;
		break;
	case 's':
		cout << "Player Attack Down" << endl;
		break;
	case 'd':
		cout << "Player Attack Right" << endl;
		break;
	default:
		break;
	}
}

void APlayer::DetectEnemy(char key)
{
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (key)
	{
	case 'w':
		if (IsMonster(CurX, CurY - 1))
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	case 'a':
		if (IsMonster(CurX - 1, CurY))
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	case 's':
		if (IsMonster(CurX, CurY + 1))
		{
			AttackFlag = true;
		}
		else
		{
			AttackFlag = false;
		}
		break;
	case 'd':
		if (IsMonster(CurX + 1, CurY))
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
		if (CanMove(CurX, CurY -1) || IsArrive(CurX, CurY - 1))
		{
			if (FGame::GetType(CurX, CurY - 1) == EType::EndPoint)
			{
				ArriveFlag = true;
			}
			MoveUp(EType::Player, CurX, CurY);
		}
		break;
	case 'a':
		if (CanMove(CurX - 1, CurY) || IsArrive(CurX - 1, CurY))
		{
			if (FGame::GetType(CurX - 1, CurY) == EType::EndPoint)
			{
				ArriveFlag = true;
			}
			MoveLeft(EType::Player, CurX, CurY);
		}

		break;
	case 's':
		if (CanMove(CurX, CurY + 1) || IsArrive(CurX, CurY + 1))
		{
			if (FGame::GetType(CurX, CurY + 1) == EType::EndPoint)
			{
				ArriveFlag = true;
			}
			MoveDown(EType::Player, CurX, CurY);
		}

		break;
	case 'd':
		if (CanMove(CurX + 1, CurY) || IsArrive(CurX + 1, CurY))
		{
			if (FGame::GetType(CurX + 1, CurY) == EType::EndPoint)
			{
				ArriveFlag = true;
			}
			MoveRight(EType::Player, CurX, CurY);
		}

		break;

	default:
		break;
	}
	PrintMove(key);
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
				AttackUp(Actor, CurX, CurY);
			}
			break;
		case 'a':
			for (AActor* Actor : FGame::GetActors())
			{
				AttackLeft(Actor, CurX, CurY);
			}
			break;
		case 's':
			for (AActor* Actor : FGame::GetActors())
			{
				AttackDown(Actor, CurX, CurY);
			}
			break;
		case 'd':
			for (AActor* Actor : FGame::GetActors())
			{
				AttackRight(Actor, CurX, CurY);
			}
			break;
		}
		PrintAttack(key);
	}
}
