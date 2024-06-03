#pragma once
#include <string>

enum class ECardType
{
	None = -1,
	Spade = 0,
	Clova,
	Heart,
	Diamond,
	Max
};

class FCard
{
public:
	FCard();
	virtual ~FCard();
	ECardType GetType();
	void SetType(ECardType NewType);
	std::string GetShape();
	void SetShape(std::string NewShape);
	int GetNumber();
	void SetNumber(int NewNumber);
	void ShowCard();

protected:
	ECardType EType;
	std::string Shape;
	int Number;
};

