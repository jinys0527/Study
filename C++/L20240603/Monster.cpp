#include "Monster.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

FMonster::FMonster()
{
	//srand((unsigned int)time(nullptr));
	//int count = 0;
	//while (count != 1)
	//{
	//	int X = rand() % 4 + 4; //4~7
	//	int Y = rand() % 4 + 4;
	//	if (FGame::GetMap()[Y][X] == EType::None)
	//	{
	//		FGame::SetType(EType::Enemy, X, Y);
	//		count++;
	//	}
	//}
	//CurDirection = 4;
}

FMonster::~FMonster()
{
}

void FMonster::Move()
{
	srand((unsigned int)time(nullptr));
	int num = rand() % 4 + 1;
	CurDirection = num;
	int CurX = MonsterPos.GetX();
	int CurY = MonsterPos.GetY();
	switch (num)
	{
	case 1:
		if (FGame::GetType(CurX, CurY - 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Enemy, CurX, CurY - 1);
			MonsterPos.SetY(CurY--);
		}
		break;
	case 2:
		if (FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Enemy, CurX - 1, CurY);
			MonsterPos.SetY(CurX--);
		}
		break;
	case 3:
		if (FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Enemy, CurX, CurY + 1);
			MonsterPos.SetY(CurY++);
		}
		break;
	case 4:
		if (FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Enemy, CurX + 1, CurY);
			MonsterPos.SetY(CurX++);
		}
		break;
	default:
		break;
	}
}

void FMonster::Attack()
{  
	int CurX = MonsterPos.GetX();
	int CurY = MonsterPos.GetY();
	switch (CurDirection)
	{
	case 1:			//W
		if (CurY > 0 && FGame::GetType(CurX, CurY - 1) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == MonsterPos.GetX() && FGame::GetActors()[i]->GetPos().GetY() == MonsterPos.GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}
		}
		break;
	case 2:			//A
		if (CurX > 0 && FGame::GetType(CurX - 1, CurY) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == MonsterPos.GetX() && FGame::GetActors()[i]->GetPos().GetY() == MonsterPos.GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}
		}
		break;
	case 3:			//S
		if (CurY < 9 && FGame::GetType(CurX, CurY + 1) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == MonsterPos.GetX() && FGame::GetActors()[i]->GetPos().GetY() == MonsterPos.GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}
		}
		break;
	case 4:			//D
		if (CurX < 9 && FGame::GetType(CurX + 1, CurY) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == MonsterPos.GetX() && FGame::GetActors()[i]->GetPos().GetY() == MonsterPos.GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}
		}
		break;
	default:
		break;
	}
}
