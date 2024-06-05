#include "Slime.h"
#include "Game.h"
#include "Util.h"

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
			cout << "Slime Move Up" << endl;
		}
		break;
	case 2:
		if (FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX - 1, CurY);
			GetPos().SetX(CurX - 1);
			cout << "Slime Move Left" << endl;
		}
		break;
	case 3:
		if (FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX, CurY + 1);
			GetPos().SetY(CurY + 1);
			cout << "Slime Move Down" << endl;
		}
		break;
	case 4:
		if (FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Slime, CurX + 1, CurY);
			GetPos().SetX(CurX + 1);
			cout << "Slime Move Right" << endl;
		}
		break;
	default:
		break;
	}
}
