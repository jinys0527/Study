#include "Game.h"
#include <iostream>
using namespace std;

std::vector<AActor*> FGame::Actors;
std::vector<std::vector<EType>> FGame::Map;

FGame::FGame()
{
	FILE* PFile = NULL;
	fopen_s(&PFile, "map.txt", "r");
	if (PFile == NULL)
	{
		perror("Error File Opening");
		return ;
	}

	char Line[255] = "";
	char* PLine;
	int j = 0;
	while (!feof(PFile))
	{
		PLine = fgets(Line, sizeof(Line), PFile);
		Map.push_back(std::vector<EType>());
		for (int i = 0; i < sizeof(Line); ++i)
		{
			switch (Line[i])
			{
			case '*':
				Map[j].push_back(EType::Wall);
				break;
			case ' ':
				Map[j].push_back(EType::None);
				break;
			case 'P':
				Map[j].push_back(EType::Player);
				break;
			case 'E':
				Map[j].push_back(EType::Enemy);
				break;
			case 'G':
				Map[j].push_back(EType::Goal);
				break;
			default:
				break;
			}
		}
		j++;
	}
	/*for (int i = 0; i < 10; ++i)
	{
		Map.push_back(std::vector<EType>());
		for (int j = 0; j < 10; ++j)
		{
			if (i == 8 && j == 8)
			{
				Map[i].push_back(EType::Goal);
			}
			else if (i == 0 || i == 9)
			{
				Map[i].push_back(EType::Wall);
			}
			else if (j == 0 || j == 9)
			{
				Map[i].push_back(EType::Wall);
			}
			else 
			{
				Map[i].push_back(EType::None);
			}
		}
	}*/
}

FGame::~FGame()
{
	for (AActor* Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void FGame::Print()
{
	for (int i = 0; i < Map.size(); ++i)
	{
		for (int j = 0; j < Map[i].size(); ++j)
		{
			switch (Map[i][j])
			{
			case EType::None:
				cout << ' ';
				break;
			case EType::Wall:
				cout << "*";
				break;
			case EType::Player:
				cout << 'P';
				break;
			case EType::Enemy:
				cout << 'E';
				break;
			case EType::Goal:
				cout << 'G';
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

EType FGame::GetType(int X, int Y)
{
	return Map[Y][X];
}

std::vector<AActor*>& FGame::GetActors()
{
	return Actors;
}

void FGame::SetType(EType NewType, int X, int Y)
{
	Map[Y][X] = NewType;
}

std::vector<std::vector<EType>> FGame::GetMap()
{
	return Map;
}
