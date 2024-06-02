#include "Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Game::Draw(Player CurPlayer)
{
	CurPlayer.Hands[CurPlayer.HandCount++] = Deck[DeckCount++];
}

void Game::Calc(Player CurPlayer)
{
	for (int i = 0; i < CurPlayer.HandCount; ++i)
	{
		CurPlayer.Score += CurPlayer.Hands[i].Number;
	}
}

void Game::Shuffle()
{

}

void Game::Judge()
{
	if (Player1.Score > 21)
	{
		Player2.Money += Player1.BetMoney;
		cout << "Player2 win \nPlayer2 Money : " << Player2.Money << endl;
		Player1.Hands.clear();
		
	}
}

void Game::Print()
{
	cout << "Player1 Money : " << Player1.Money << "Hands : ";
	Player1.PrintHand();
	cout << "Player1 BetMoney : " << Player1.BetMoney << endl;
	cout << "Player2 Money : " << Player2.Money << "Hands : ";
	Player2.PrintHand();
	cout << "Player2 BetMoney : " << Player2.BetMoney << endl;
}