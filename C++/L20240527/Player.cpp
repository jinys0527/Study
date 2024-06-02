#include "Player.h"
#include <iostream>
using namespace std;

FPlayer::FPlayer()
{
	Gold = 100;
	cout << "Player »ý¼º" << endl;
}

FPlayer::~FPlayer()
{

}

void FPlayer::Get()
{
}

int FPlayer::GetGold()
{
	return Gold;
}

void FPlayer::SetGold(int NewGold)
{
	if (NewGold >= 0)
	{
		Gold = NewGold;
	}
}
