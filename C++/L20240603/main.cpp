#include <conio.h>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
#include "Util.h"
using namespace std;

int main()
{
	srand((unsigned int)time(nullptr));
	FGame* Game = new FGame();
	char key;
	
	while (true)
	{
		Game->Print();
		key = _getch();
		if (key == 'q')
			break;
		for (int i = 0; i < Game->GetActors().size(); ++i)
		{
			if (i == 0)
			{
				Game->GetActors()[i]->Move(key);
				Game->GetActors()[i]->PrintMove(key);
				cout << "Press any Key" << endl;
				_getch();
				if (Game->GetActors()[i]->GetArriveFlag())
				{
					system("cls");
					Game->Print();
					cout << "Clear" << endl;
					return 0;
				}
				system("cls");
				Game->Print();
				key = _getch();
				if (key == 'q')
					break;
				Game->GetActors()[i]->Attack(key);
				Game->GetActors()[i]->PrintAttack(key);
				cout << "Press any Key" << endl;
				_getch();
				system("cls");
				Game->Print();
			}
			else
			{
				Game->GetActors()[i]->Move();
				cout << "Press any Key" << endl;
				_getch();
				system("cls");
				Game->Print();
				Game->GetActors()[i]->Attack();
				cout << "Press any Key" << endl;
				_getch();
				system("cls");
				Game->Print();
			}
		}
		_getch();
		system("cls");
	}
	
	for (AActor* Actor : Game->GetActors())
	{
		delete Actor;
	}

	Game->GetActors().clear();

	delete Game;

	return 0;
}