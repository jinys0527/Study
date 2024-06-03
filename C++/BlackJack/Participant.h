#pragma once
#include <vector>
using namespace std;

class FCard;

class FParticipant
{
public:
	FParticipant();
	virtual ~FParticipant();
	void Betting(int BetMoney);
	void Draw();
	void Fold();
protected:
	vector<FCard*> Hand;
	int Money;
	int BetMoney;
};

