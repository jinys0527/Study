#include <iostream>
#include <conio.h>

using namespace std;

int PlayerX = 1;
int PlayerY = 1;
int PlayerHp = 100;
char PlayerShape = 'P';

int MonsterX = 6;
int MonsterY = 6;
char MonsterShape = 'M';

int GoalX = 8;
int GoalY = 8;
char GoalShape = 'G';

char FloorShape = ' ';
char WallShape = '*';

int Key = 0;

int World[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool IsRunning = true;

void Input()
{
	Key = _getch();
}

bool IsBlock(int Y, int X) 
{
	if (World[Y][X] == 1)
		return true;
	else
		return false;
}

void Tick()
{
	if (Key == 'w' && !IsBlock(PlayerY-1, PlayerX))
	{
		PlayerY--;
	}
	else if (Key == 'a' && !IsBlock(PlayerY, PlayerX - 1))
	{
		PlayerX--;
	}
	else if (Key == 's' && !IsBlock(PlayerY + 1, PlayerX))
	{
		PlayerY++;
	}
	else if (Key == 'd' && !IsBlock(PlayerY, PlayerX + 1))
	{
		PlayerX++;
	}
	else if (Key == 27)
	{
		IsRunning = false;
	}
	int Case = rand() % 4;
	if (Case == 0 && !IsBlock(MonsterY - 1, MonsterX) && MonsterY-1!=GoalY)
	{
		MonsterY--;
	}
	else if (Case == 1 && !IsBlock(MonsterY, MonsterX - 1) && MonsterX - 1 != GoalY)
	{
		MonsterX--;
	}
	else if (Case == 2 && !IsBlock(MonsterY + 1, MonsterX) && MonsterY + 1 != GoalY)
	{
		MonsterY++;
	}
	else if (Case == 3 && !IsBlock(MonsterY, MonsterX + 1) && MonsterX + 1 != GoalY)
	{
		MonsterX++;
	}

	if (PlayerX == MonsterX && PlayerY == MonsterY) 
	{
		PlayerHp -= 10;
	}

	if (PlayerHp == 0)
	{
		cout << "Game Over" << endl;
		IsRunning = false;
	}

	if(PlayerX == GoalX && PlayerY == GoalY) 
	{
		cout << "Clear" << endl;;
		IsRunning = false;
	}
}

void Render() 
{
	system("cls");
	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << PlayerShape;
			}
			else if (MonsterX == X && MonsterY == Y) 
			{
				cout << MonsterShape;
			}
			else if (GoalX == X && GoalY == Y)
			{
				cout << GoalShape;
			}
			else if (World[Y][X] == 1)
			{
				cout << WallShape;
			}
			else if (World[Y][X] == 0) 
			{
				cout << FloorShape;
			}
		}
		cout << endl;
	}
	cout << "PlayerHp : " << PlayerHp << endl;
}

int main()
{
	while (IsRunning)
	{
		Input();
		Tick();
		Render();
	}

	return 0;
}