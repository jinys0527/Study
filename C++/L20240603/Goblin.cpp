#include "Goblin.h"
#include "Game.h"
#include "Util.h"

FGoblin::FGoblin()
{
	SetType(EType::Goblin);
	Name = "Goblin";
}

FGoblin::~FGoblin()
{

}

FGoblin::FGoblin(int X, int Y)
{
	GetPos().SetX(X);
	GetPos().SetY(Y);
	SetType(EType::Goblin);
	Name = "Goblin";
}

void FGoblin::Move()
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
			FGame::SetType(EType::Goblin, CurX, CurY - 1);
			GetPos().SetY(CurY - 1);
			cout << "Goblin Move Up" << endl;
		}
		break;
	case 2:
		if (FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Goblin, CurX - 1, CurY);
			GetPos().SetX(CurX - 1);
			cout << "Goblin Move Left" << endl;
		}
		break;
	case 3:
		if (FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Goblin, CurX, CurY + 1);
			GetPos().SetY(CurY + 1);
			cout << "Goblin Move Down" << endl;
		}
		break;
	case 4:
		if (FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Goblin, CurX + 1, CurY);
			GetPos().SetX(CurX + 1);
			cout << "Goblin Move Right" << endl;
		}
		break;
	default:
		break;
	}
}
