#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(vector<Card> Hands, int Hand, int Score, int Money, int BetMoney)
{
	this->Hands = Hands;
	this->HandCount = Hand;
	this->Score = Score;
	this->Money = Money;
	this->BetMoney = BetMoney;
}

void Player::Betting(int Money)
{
	this->BetMoney += Money;
}

void Player::PrintHand()
{
	for (int i = 0; i < HandCount; ++i)
	{
		cout << Hands[i].Shape << ' ' << Hands[i].Number<<' ';
	}
}