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
			FGame::SetType(EType::Boar, CurX, CurY - 1);
			GetPos().SetY(CurY - 1);
			cout << "Boar Move Up" << endl;
		}
		break;
	case 2:
		if (FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Boar, CurX - 1, CurY);
			GetPos().SetX(CurX - 1);
			cout << "Boar Move Left" << endl;
		}
		break;
	case 3:
		if (FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Boar, CurX, CurY + 1);
			GetPos().SetY(CurY + 1);
			cout << "Boar Move Down" << endl;
		}
		break;
	case 4:
		if (FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Boar, CurX + 1, CurY);
			GetPos().SetX(CurX + 1);
			cout << "Boar Move Right" << endl;
		}
		break;
	default:
		break;
	}
}
