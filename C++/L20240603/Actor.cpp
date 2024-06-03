#include "Actor.h"

AActor::AActor()
{
	HP = 100;
}

AActor::~AActor()
{
}

int AActor::GetHP()
{
	return HP;
}

void AActor::SetHP(int NewHP)
{
	HP = NewHP;
}

void AActor::Move(char key)
{
	switch (key)
	{
	case 'w':

	}
}

void AActor::Attack()
{
}

void AActor::Die()
{
}
