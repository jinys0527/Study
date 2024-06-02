#pragma once
#include "Player.h"
#include "Monster.h"

class FWorld
{
public:
	FWorld(); //기본 생성자
	~FWorld(); //소멸자
	AActor WorldActor;
};

