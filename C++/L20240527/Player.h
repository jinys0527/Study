#pragma once
#include "Actor.h"

class FPlayer : public AActor
{
public: //����������
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

