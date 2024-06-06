#include "Boar.h"
#include "Game.h"
#include "Util.h"

FBoar::FBoar()
{
	SetType(EType::Boar);
	Name = "Boar";
}

FBoar::~FBoar()
{
}

FBoar::FBoar(int X, int Y)
{
	GetPos().SetX(X);
	GetPos().SetY(Y);
	SetType(EType::Boar);
	Name = "Boar";
}

void FBoar::Move()
{
	int num = 1;
	CurDirection = num;
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (num)
	{
	case 1:
		if (CanMove(CurX, CurY - 1))
		{
			MoveUp(EType::Boar, CurX, CurY);
			cout << "Boar Move Up" << endl;
		}
		break;
	case 2:
		if (CanMove(CurX - 1, CurY))
		{
			MoveLeft(EType::Boar, CurX, CurY);
			cout << "Boar Move Left" << endl;
		}
		break;
	case 3:
		if (CanMove(CurX, CurY + 1))
		{
			MoveDown(EType::Boar, CurX, CurY);
			cout << "Boar Move Down" << endl;
		}
		break;
	case 4:
		if (CanMove(CurX + 1, CurY))
		{
			MoveRight(EType::Boar, CurX, CurY);
			cout << "Boar Move Right" << endl;
		}
		break;
	default:
		break;
	}
}
