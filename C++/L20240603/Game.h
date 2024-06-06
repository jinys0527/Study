#pragma once
#include "Actor.h"
#include <vector>


class FGame
{
public:
	FGame();
	virtual ~FGame();
	static void Print();
	static EType GetType(int X, int Y);
	static std::vector<AActor*>& GetActors();
	static void SetType(EType NewType, int X, int Y);
	static std::vector<std::vector<EType>> GetMap();
	static void Update();
	static bool Restart();
	static void ResetMap();
	static void DestroyActor(AActor* Actor, int X, int Y);
protected:
	static std::vector<AActor*> Actors;
	static std::vector<std::vector<EType>> Map;
};

