#include "Player.h"
#include "Game.h"

APlayer::APlayer()
{
	/*PlayerPos.SetX(1);
	PlayerPos.SetY(1);
	FGame::SetType(EType::Player, 1, 1);*/
}

APlayer::~APlayer()
{
}

bool APlayer::GetAttackFlag()
{
	return AttackFlag;
}

void APlayer::SetAttackFlag(bool NewFlag)
{
	AttackFlag = NewFlag;
}

void APlayer::DetectEnemy(char key)
{
	int CurX = PlayerPos.GetX();
	int CurY = PlayerPos.GetY();
	switch (key)
	{
	case 'w':
		if (FGame::GetType(CurX, CurY - 1) == EType::Enemy)
		{
			AttackFlag = true;
		}
		break;
	case 'a':
		if (FGame::GetType(CurX - 1, CurY) == EType::Enemy)
		{
			AttackFlag = true;
		}
		break;
	case 's':
		if (FGame::GetType(CurX, CurY + 1) == EType::Enemy)
		{
			AttackFlag = true;
		}
		break;
	case 'd':
		if (FGame::GetType(CurX + 1, CurY) == EType::Enemy)
		{
			AttackFlag = true;
		}
		break;
	}
}

void APlayer::Move(char key)
{
	int CurX = PlayerPos.GetX();
	int CurY = PlayerPos.GetY();
	switch (key)
	{
	case 'w':
		if (CurY > 0 && FGame::GetType(CurX, CurY - 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX, CurY - 1);
			PlayerPos.SetY(CurY--);
		}
		break;
	case 'a':
		if (CurX > 0 && FGame::GetType(CurX - 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX - 1, CurY);
			PlayerPos.SetX(CurX--);
		}
		break;
	case 's':
		if (CurY < 9 && FGame::GetType(CurX, CurY + 1) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX, CurY + 1);
			PlayerPos.SetY(CurY++);
		}
		break;
	case 'd':
		if (CurX < 9 && FGame::GetType(CurX + 1, CurY) == EType::None)
		{
			FGame::SetType(EType::None, CurX, CurY);
			FGame::SetType(EType::Player, CurX + 1, CurY);
			PlayerPos.SetX(CurX++);
		}
		break;
	default:
		break;
	}

	Direction = key;
}

void APlayer::Attack(char key)
{
	if (AttackFlag == true)
	{
		DetectEnemy(key);
		switch (key)
		{
		case 'w':
			for (int i = 0; i < FGame::GetActors().size(); ++i)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == PlayerPos.GetX() && FGame::GetActors()[i]->GetPos().GetY() == PlayerPos.GetY() - 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}
			break;
		case 'a':

			for (int i = 0; i < FGame::GetActors().size(); ++i)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == PlayerPos.GetX() - 1 && FGame::GetActors()[i]->GetPos().GetY() == PlayerPos.GetY())
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}

			break;
		case 's':

			for (int i = 0; i < FGame::GetActors().size(); ++i)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == PlayerPos.GetX() && FGame::GetActors()[i]->GetPos().GetY() == PlayerPos.GetY() + 1)
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}

			break;
		case 'd':

			for (int i = 0; i < FGame::GetActors().size(); ++i)
			{
				if (FGame::GetActors()[i]->GetPos().GetX() == PlayerPos.GetX() + 1 && FGame::GetActors()[i]->GetPos().GetY() == PlayerPos.GetY())
				{
					FGame::GetActors()[i]->SetHP(FGame::GetActors()[i]->GetHP() - 10);
				}
			}

			break;
		}
	}
}
