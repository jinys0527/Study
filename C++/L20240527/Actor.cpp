#include "Actor.h"

AActor::AActor()
{
	HealthPoint = 100;
}

AActor::~AActor()
{
}

int AActor::GetHealthPoint()
{
	return HealthPoint;
}

void AActor::SetHealthPoint(int NewHealthPoint)
{
	HealthPoint = NewHealthPoint;
}

void AActor::Die()
{
	HealthPoint = 0;
}
