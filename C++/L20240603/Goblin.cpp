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
		if (CanMove(CurX, CurY - 1))
		{
			MoveUp(EType::Goblin, CurX, CurY);
			cout << "Goblin Move Up" << endl;
		}
		break;
	case 2:
		if (CanMove(CurX - 1, CurY))
		{
			MoveLeft(EType::Goblin, CurX, CurY);
			cout << "Goblin Move Left" << endl;
		}
		break;
	case 3:
		if (CanMove(CurX, CurY + 1))
		{
			MoveDown(EType::Goblin, CurX, CurY);
			cout << "Goblin Move Down" << endl;
		}
		break;
	case 4:
		if (CanMove(CurX + 1, CurY))
		{
			MoveRight(EType::Goblin, CurX, CurY);
			cout << "Goblin Move Right" << endl;
		}
		break;
	default:
		break;
	}
}
