#pragma once
#include "Actor.h"
#include <ctime>
#include <cstdlib>

class FMonster : public AActor
{
public:
	FMonster();
	virtual ~FMonster();
	void Drop();
	virtual void Move();
};
