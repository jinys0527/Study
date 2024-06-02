#pragma once
#include "Card.h"
#include <vector>

class Player
{
public:
	vector<Card> Hands;
	int HandCount;
	int Score;
	int Money;
	int BetMoney;
	Player(vector<Card> Hands, int Hand, int Score, int Money, int BetMoney);
	void Betting(int Money);
	void PrintHand();
};

