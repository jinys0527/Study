#pragma once
#include <vector>
using namespace std;

class FCard;

class FDeck
{
public:
	FDeck();
	virtual ~FDeck();
	void Shuffle();
protected:
	vector<FCard*> Deck;
	int Count = 0;

};

