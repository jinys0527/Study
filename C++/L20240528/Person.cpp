#include "Person.h"
#include "Card.h"

FPerson::FPerson()
{
}

FPerson::~FPerson()
{
}

void FPerson::Draw(FCard* NewCard)
{
	Cards.push_back(NewCard);
}

int FPerson::Check()
{
	int Total = 0;

	for (auto Card : Cards)
	{
		Total += Card->GetScore();
	}

	return Total;
}

void FPerson::Show()
{
	for (auto Card : Cards)
	{
		Card->Show();
	}
}
