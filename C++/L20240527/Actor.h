#pragma once
#include "Action.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();
	FAction ActorAction;
	int GetHealthPoint();
	void SetHealthPoint(int NewHealthPoint);
	void Die();
	
protected:
	int HealthPoint;
	
};

