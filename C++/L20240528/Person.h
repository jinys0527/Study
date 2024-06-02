#pragma once
#include <vector>

class FCard;

class FPerson
{
public:
	FPerson();
	virtual ~FPerson();
	void Draw(FCard* NewCard);
	int Check();
	void Show();

protected:
	std::vector<FCard*> Cards;
};

