#include "Game.h"
#include "Player.h"
#include "Goblin.h"
#include "Boar.h"
#include "Slime.h"
#include "Monster.h"
#include <fstream>
#include "Util.h"

std::vector<AActor*> FGame::Actors;
std::vector<std::vector<EType>> FGame::Map;

FGame::FGame()
{
	ifstream InputFile;
	char Line[255] = "";

	InputFile.open("map.txt");

	int j = 0;
	while (InputFile.getline(Line, 255))
	{
		Map.push_back(std::vector<EType>());
		for (int i = 0; i < strlen(Line); ++i)
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
				Actors.push_back(new APlayer(i-1, j));
				break;
			case 'E':
				Map[j].push_back(EType::EndPoint);
				break;
			case 'G':
				Map[j].push_back(EType::Goblin);
				Actors.push_back(new FGoblin(i-1, j));
				break;
			case 'B':
				Map[j].push_back(EType::Boar);
				Actors.push_back(new FBoar(i-1, j));
				break;
			case 'S':
				Map[j].push_back(EType::Slime);
				Actors.push_back(new FSlime(i-1, j));
				break;
			default:
				break;
			}
		}
		j++;
	}

	InputFile.close();
	/*FILE* PFile = NULL;
	fopen_s(&PFile, "map.txt", "r");
	if (PFile == NULL)
	{
		perror("Error File Opening");
		return ;
	}*/

	
	
	/*while (!feof(PFile))
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
				Actors.push_back(new APlayer(i, j));
				break;
			case 'E':
				Map[j].push_back(EType::EndPoint);
				break;
			case 'G':
				Map[j].push_back(EType::Goblin);
				Actors.push_back(new FGoblin(i, j));
				break;
			case 'B':
				Map[j].push_back(EType::Boar);
				Actors.push_back(new FBoar(i, j));
				break;
			case 'S':
				Map[j].push_back(EType::Slime);
				Actors.push_back(new FSlime(i, j));
				break;
			default:
				break;
			}
		}
		j++;
	}

	fclose(PFile);*/
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
			case EType::EndPoint:
				cout << 'E';
				break;
			case EType::Goblin:
				cout << 'G';
				break;
			case EType::Boar:
				cout << 'B';
				break;
			case EType::Slime:
				cout << 'S';
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

void FGame::Update()
{
	system("cls");
	Print();
}

bool FGame::Restart()
{
	if (APlayer::GetFlag() == true)
	{
		return true;
	}
	return false;
}

void FGame::ResetMap()
{
	Map.clear();
}

void FGame::DestroyActor(AActor* Actor, int X, int Y)
{
	SetType(EType::None, X, Y);
	delete Actor;
	GetActors().erase(std::remove(FGame::GetActors().begin(), FGame::GetActors().end(), Actor), FGame::GetActors().end());
	Update();
}
