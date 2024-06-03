#include "Deck.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

FDeck::FDeck()
{
	for (int Type = 0; Type < 4; ++Type)
	{

	}
}

FDeck::~FDeck()
{
	for (int i = 0; i < Deck.size(); ++i)
	{
		delete Deck[i];
	}
	Deck.clear();
}

void FDeck::Shuffle()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::shuffle(Deck.begin(), Deck.end(), gen);
}