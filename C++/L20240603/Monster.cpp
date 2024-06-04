#include "Monster.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

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
	CurDirection = 3;
}

FMonster::~FMonster()
{
}

void FMonster::Move()
{
	
}

void FMonster::Attack()
{  
	int CurX = GetPos().GetX();
	int CurY = GetPos().GetY();
	switch (CurDirection)
	{
	case 1:			//W
		if (CurY > 0 && FGame::GetType(CurX, CurY - 1) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == GetPos().GetX() && FGame::GetActors()[i]->GetPos().GetY() == GetPos().GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
					cout << FGame::GetActors()[i]->GetName() << FGame::GetActors()[i]->GetHP();
				}
			}
		}
		break;
	case 2:			//A
		if (CurX > 0 && FGame::GetType(CurX - 1, CurY) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == GetPos().GetX() && FGame::GetActors()[i]->GetPos().GetY() == GetPos().GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
					cout << FGame::GetActors()[i]->GetName() << FGame::GetActors()[i]->GetHP();
				}
			}
		}
		break;
	case 3:			//S
		if (CurY < 9 && FGame::GetType(CurX, CurY + 1) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == GetPos().GetX() && FGame::GetActors()[i]->GetPos().GetY() == GetPos().GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
					cout << FGame::GetActors()[i]->GetName() << FGame::GetActors()[i]->GetHP();
				}
			}
		}
		break;
	case 4:			//D
		if (CurX < 9 && FGame::GetType(CurX + 1, CurY) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == GetPos().GetX() && FGame::GetActors()[i]->GetPos().GetY() == GetPos().GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
					cout << FGame::GetActors()[i]->GetName() << FGame::GetActors()[i]->GetHP();
				}
			}
		}
		break;
	default:
		break;
	}
}
