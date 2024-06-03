#pragma once
#include "Actor.h"
class FPlayer : public AActor
{
public:
	FPlayer();
	virtual ~FPlayer();
protected:
	void GameOver();
	void Restart(int key);
};

