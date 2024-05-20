#include <iostream>
using namespace std;


int main()
{
	int Map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int PlayerX = 1;
	int PlayerY = 1;
	int PlayerHp = 100;
	char Key = 0;
	int MonsterX = 7;
	int MonsterY = 7;
	int EndPointX = 8;
	int EndPointY = 8;

	for (;;)
	{
		for (int Y = 0; Y < 10; ++Y)
		{
			for (int X = 0; X < 10; ++X)
			{
				if (PlayerY == Y && PlayerX == X)
				{
					cout << "P";
				}
				else if (MonsterY == Y && MonsterX == X)
				{
					cout << "M";
				}
				else if (EndPointY == Y && EndPointX == X)
				{
					cout << "E";
				}
				else if (Map[Y][X] == 1)
				{
					cout << "*";
				}
				else if (Map[Y][X] == 0)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << "HP : " << PlayerHp << endl;
		cin >> Key; //wasd
		if (Key == 'w')
		{
			if (Map[PlayerY - 1][PlayerX] != 1)
			{
				PlayerY--;
			}
		}
		else if (Key == 'a')
		{
			if (Map[PlayerY][PlayerX - 1] != 1)
			{
				PlayerX--;
			}
		}
		else if (Key == 's')
		{
			if (Map[PlayerY + 1][PlayerX] != 1)
			{
				PlayerY++;
			}
		}
		else if (Key == 'd')
		{
			if (Map[PlayerY][PlayerX + 1] != 1)
			{
				PlayerX++;
			}

		}
		int Case = rand() % 4;
		if (Case == 0) {
			if (Map[MonsterY - 1][MonsterX] != 1 && MonsterY-1 != EndPointY)
			{
				MonsterY--;
			}
		}
		else if (Case == 1) {
			if (Map[MonsterY][MonsterX - 1] != 1 && MonsterX-1 != EndPointX)
			{
				MonsterX--;
			}
		}
		else if (Case == 2) {
			if (Map[MonsterY + 1][MonsterX] != 1 && MonsterY+1 != EndPointY)
			{
				MonsterY++;
			}
		}
		else if (Case == 3) {
			if (Map[MonsterY][MonsterX + 1] != 1 && MonsterX+1 != EndPointX)
			{
				MonsterX++;
			}
		}

		if (PlayerY == MonsterY && PlayerX == MonsterX)
		{
			PlayerHp -= 10;
		}

		if (PlayerHp == 0)
		{
			cout << "Game Over"<<endl;
			break;
		}

		if (PlayerY == EndPointY && PlayerX == EndPointX)
		{
			cout << "Clear" << endl;
			break;
		}

		system("cls");
	}

	//GameLoop
	/*for (;;)  Frame, 60FPS
	{
		Input();
		Process();
		Tick(); CPU 1clock
		Render();
	}*/

	return 0;
}