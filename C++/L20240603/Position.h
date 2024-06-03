#pragma once
class FPosition
{
public:
	FPosition();
	virtual ~FPosition();
	int GetX();
	int GetY();
	void SetX(int NewX);
	void SetY(int NewY);
protected:
	int X;
	int Y;
};

