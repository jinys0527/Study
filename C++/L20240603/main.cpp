#include <conio.h>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
#include "Util.h"
using namespace std;

void delay()
{
	cout << "Press any Key" << endl;
	_getch();
}

int main()
{
	srand((unsigned int)time(nullptr));
	FGame* Game = new FGame();
	char key;
	
	while (true)
	{
		if (Game->Restart())
		{
			cout << "Game Over!" << endl;
			cout << "Restart" << endl;
			delay();
			for (AActor* Actor : Game->GetActors())
			{
				delete Actor;
			}

			Game->GetActors().clear();
			Game->ResetMap();

			Game = new FGame();
		}
		Game->Update();
		key = _getch();
		if (key == 'q')
			break;
		for (int i = 0; i < Game->GetActors().size(); ++i)
		{
			if (i == 0)
			{
				Game->GetActors()[i]->Move(key);
				delay();
				if (Game->GetActors()[i]->GetArriveFlag())
				{
					Game->Update();
					cout << "Clear" << endl;
					return 0;
				}
				Game->Update();
				key = _getch();
				if (key == 'q')
					break;
				Game->GetActors()[i]->Attack(key);
				delay();
				Game->Update();
			}
			else
			{
				Game->GetActors()[i]->Move();
				delay();
				Game->Update();
				Game->GetActors()[i]->Attack();
				delay();
				Game->Update();
			}
		}
	}
	
	for (AActor* Actor : Game->GetActors())
	{
		delete Actor;
	}

	Game->GetActors().clear();

	delete Game;

	return 0;
}