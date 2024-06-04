#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
#include <windows.h>
using namespace std;

int main()
{
	srand((unsigned int)time(nullptr));
	FGame* Game = new FGame();
	Game->GetActors().push_back(new APlayer());
	EType type;
	char key;

	for (int i = 0; i < 5; ++i)
	{
		int num = rand() % 3 + 1;
		switch (num)
		{
		case 1:
			Game->GetActors().push_back(new FGoblin());
			break;
		case 2:
			Game->GetActors().push_back(new FSlime());
			break;
		case 3:
			Game->GetActors().push_back(new FBoar());
			break;
		}
	}

	/*for (int i=0;i<Game->GetActors().size();++i)
	{
		type = Game->GetType(Game->GetActors()[i]->GetPos().GetX(), Game->GetActors()[i]->GetPos().GetY());
		switch (type)
		{
		case EType::None:
			cout << "None";
			break;
		case EType::Wall:
			cout << "Wall";
			break;
		case EType::Player:
			cout << "Player";
			break;
		case EType::Enemy:
			cout << "Enemy";
			break;
		case EType::Max:
			cout << "Max";
			break;
		}
	}*/
	Game->Print();

	//while (true)
	//{
	//	Game->Print();
	//	key = _getch();
	//	for (int i = 0; i < Game->GetActors().size(); ++i)
	//	{
	//		if (i == 0)
	//		{
	//			type = Game->GetType(Game->GetActors()[i]->GetPos().GetX(), Game->GetActors()[i]->GetPos().GetY());
	//			switch (type)
	//			{
	//			case EType::None:
	//				cout << "None";
	//				break;
	//			case EType::Wall:
	//				cout << "Wall";
	//				break;
	//			case EType::Player:
	//				cout << "Player";
	//				break;
	//			case EType::Enemy:
	//				cout << "Enemy";
	//				break;
	//			case EType::Max:
	//				cout << "Max";
	//				break;
	//			}
	//		//	Game->GetActors()[i]->Move(key);
	//			Game->GetActors()[i]->Attack(key);
	//		}
	//		else
	//		{
	//		//	Game->GetActors()[i]->Move();
	//			Game->GetActors()[i]->Attack();
	//		}
	//	}
	//	Sleep(500);
	//	system("cls");
	//	if (key == 'q')
	//		break;
	//}
	
	for (AActor* Actor : Game->GetActors())
	{
		delete Actor;
	}

	Game->GetActors().clear();

	delete Game;

	return 0;
}