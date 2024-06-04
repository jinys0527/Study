#include "Position.h"

FPosition::FPosition()
{
	X = 0;
	Y = 0;
}

FPosition::~FPosition()
{
}

int& FPosition::GetX()
{
	return X;
}

int& FPosition::GetY()
{
	return Y;
}

void FPosition::SetX(int NewX)
{
	X = NewX;
}

void FPosition::SetY(int NewY)
{
	Y = NewY;
}

