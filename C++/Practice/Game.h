#pragma once
#include "Player.h"

class Game
{
public:
	Player Player1;
	Player Player2;
	Card Deck[52];
	int DeckCount;
	void Draw(Player CurPlayer);
	void Calc(Player CurPlayer);
	void Shuffle();
	void Judge();
	void Print();
};

