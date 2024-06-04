#include "Slime.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>


FSlime::FSlime()
{
	SetType(EType::Slime);
	Name = "Slime";
}

FSlime::~FSlime()
{
}

FSlime::FSlime(int X, int Y)
{
	GetPos().SetX(X);
	GetPos().SetY(Y);
	SetType(EType::Slime);
	Name = "Slime";
}

void FSlime::Move()
{
	int num = rand() % 4 + 1;
	CurDirection = num;
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (num)
	{
	case 1:
		if (FGame::GetType(CurX, CurY - 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX, CurY - 1);
			GetPos().SetY(CurY - 1);
		}
		break;
	case 2:
		if (FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX - 1, CurY);
			GetPos().SetX(CurX - 1);
		}
		break;
	case 3:
		if (FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX, CurY + 1);
			GetPos().SetY(CurY + 1);
		}
		break;
	case 4:
		if (FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX + 1, CurY);
			GetPos().SetX(CurX + 1);
		}
		break;
	default:
		break;
	}
}
