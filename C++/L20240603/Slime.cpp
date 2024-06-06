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
	int num = 2;
	CurDirection = num;
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (num)
	{
	case 1:
		if (CanMove(CurX, CurY - 1))
		{
			MoveUp(EType::Slime, CurX, CurY);
			cout << "Slime Move Up" << endl;
		}
		break;
	case 2:
		if (CanMove(CurX - 1, CurY))
		{
			MoveLeft(EType::Slime, CurX, CurY);
			cout << "Slime Move Left" << endl;
		}
		break;
	case 3:
		if (CanMove(CurX, CurY + 1))
		{
			MoveDown(EType::Slime, CurX, CurY);
			cout << "Slime Move Down" << endl;
		}
		break;
	case 4:
		if (CanMove(CurX + 1, CurY))
		{
			MoveRight(EType::Slime, CurX, CurY);
			cout << "Slime Move Right" << endl;
		}
		break;
	default:
		break;
	}
}
