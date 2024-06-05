#include "Monster.h"
#include "Game.h"
#include "Util.h"

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
	int num = rand() % 4 + 1;
	CurDirection = num;
	switch (num)
	{
	case 1:			//W
		if (CurY > 0 && FGame::GetType(CurX, CurY - 1) == EType::Player)
		{
			for (int i = 0; i < FGame::GetActors().size(); i++)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == GetPos().GetX() && FGame::GetActors()[i]->GetPos().GetY() == GetPos().GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
					cout << FGame::GetActors()[i]->GetName() << " : " << FGame::GetActors()[i]->GetHP();
				}
			}
		}
		PrintType();
		cout << " Attack Up" << endl;
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
		PrintType();
		cout << " Attack Left" << endl;
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
		PrintType();
		cout << " Attack Down" << endl;
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
		PrintType();
		cout << " Attack Right" << endl;
		break;
	default:
		break;
	}
}
