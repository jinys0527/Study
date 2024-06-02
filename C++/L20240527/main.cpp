#include <iostream>
#include "World.h"
#include "Player.h"
#include "Goblin.h"
#include "Boar.h"
#include "Slime.h"
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	////Player 1
	//// 1~3
	//srand((unsigned int)time(nullptr));
	//FPlayer Player;
	//int GoblinCount = rand() % 3 + 1;
	//vector<FGoblin*> Goblins;
	//int SlimeCount = rand() % 3 + 1;
	//vector<FSlime*> Slimes;
	//int BoarCount = rand() % 3 + 1;
	//vector<FBoar*> Boars;

	//for (int i = 0; i < GoblinCount; ++i)
	//{
	//	Goblins.push_back(new FGoblin());
	//	Goblins[i]->Move();
	//}

	//for (int i = 0; i < SlimeCount; ++i)
	//{
	//	Slimes.push_back(new FSlime());
	//	Slimes[i]->Move();
	//}

	//for (int i = 0; i < BoarCount; ++i)
	//{
	//	Boars.push_back(new FBoar());
	//	Boars[i]->Move();
	//}

	//for (int i = 0; i < GoblinCount; ++i)
	//{
	//	delete Goblins[i];
	//}

	//for (int i = 0; i < SlimeCount; ++i)
	//{
	//	delete Slimes[i];
	//}

	//for (int i = 0; i < BoarCount; ++i)
	//{
	//	delete Boars[i];
	//}


	//Goblins.clear();
	//Slimes.clear();
	//Boars.clear();

	/*vector<FMonster*> Monsters;
	Monsters.push_back(new FGoblin);
	Monsters.push_back(new FSlime);
	Monsters.push_back(new FSlime);
	Monsters.push_back(new FBoar);

	for (int i = 0; i < Monsters.size(); ++i)
	{
		Monsters[i]->Move();
	}
	
	for (int i = 0; i < Monsters.size(); ++i)
	{
		delete Monsters[i];
	}

	Monsters.clear();*/

	return 0;
}