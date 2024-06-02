#pragma once
#include <vector>

class FCard;

class FDeck
{
public:
	FDeck();
	virtual ~FDeck();
	int Count = 0;
	void Check();
	int CurrentPosition;
	FCard* Draw();

protected:
	std::vector<FCard*> Cards;

};

