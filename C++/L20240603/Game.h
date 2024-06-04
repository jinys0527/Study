#pragma once
#include "Actor.h"
#include <vector>


class FGame
{
public:
	FGame();
	virtual ~FGame();
	void Print();
	static EType GetType(int X, int Y);
	static std::vector<AActor*>& GetActors();
	static void SetType(EType NewType, int X, int Y);
	static std::vector<std::vector<EType>> GetMap();
protected:
	static std::vector<AActor*> Actors;
	static std::vector<std::vector<EType>> Map;
};

