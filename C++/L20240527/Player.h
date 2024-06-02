#pragma once
#include "Actor.h"

class FPlayer : public AActor
{
public: //접근지정자
	FPlayer();
	virtual ~FPlayer();

	//interface
	void Get();

	//accessor
	int GetGold();
	//mutator
	void SetGold(int NewGold);
private:
	int Gold;
	
};

