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
	char key;

	vector<vector<EType>> Test;

	/*while (true)
	{
		Test = Game->GetMap();
		for (int i = 0; i < Test.size(); ++i)
		{
			for (int j = 0; j < Test[i].size(); ++j)
			{
				switch (Test[i][j])
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
				case EType::EndPoint:
					cout << "EndPoint";
					break;
				case EType::Goblin:
					cout << "Goblin";
					break;
				case EType::Boar:
					cout << "Boar";
					break;
				case EType::Slime:
					cout << "Slime";
					break;
				default:
					break;
				}
			}
			cout << endl;
		}
		
		key = _getch();
		Game->GetActors()[0]->Move(key);
	}*/
	

	while (true)
	{
		Game->Print();
		key = _getch();
		for (int i = 0; i < Game->GetActors().size(); ++i)
		{
			if (i == 0)
			{
				Game->GetActors()[i]->Move(key);
				Game->GetActors()[i]->Attack(key);
			}
			else
			{
				Game->GetActors()[i]->Move();
				Game->GetActors()[i]->Attack();
			}
		}
		Sleep(500);
		system("cls");
		if (key == 'q')
			break;
	}
	
	for (AActor* Actor : Game->GetActors())
	{
		delete Actor;
	}

	Game->GetActors().clear();

	delete Game;

	return 0;
}