#pragma once
#include <string>

enum class ECardType
{
	None = -1,
	Clova = 0,
	Spade,
	Heart,
	Diamond,
	Max
};

class FCard
{
public:
	FCard();
	virtual ~FCard();
	void SetShape(std::string NewShape);
	void SetNumber(int NewNumber);
	void SetType(ECardType NewCardType);
	int GetScore();

protected:
	ECardType Type;
	std::string Shape;
	int Number;
	void ShowNumber();

public:
	void Show();
};

