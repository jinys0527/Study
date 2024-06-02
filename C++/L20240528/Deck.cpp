#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>


FDeck::FDeck()
{
	for (int Type = 0; Type < 4; ++Type)
	{
		for (int Number = 1; Number <= 13; ++Number)
		{
			FCard* Temp = new FCard();
			/*switch (Type)
			{
				case 0:
					Temp->SetType(ECardType::Clova);
					break;
				case 1:
					Temp->SetType(ECardType::Spade);
					break;
				case 2:
					Temp->SetType(ECardType::Heart);
					break;
				case 3:
					Temp->SetType(ECardType::Diamond);
					break;
			}*/
			Temp->SetType(static_cast<ECardType>(Type));
			Temp->SetNumber(Number);
			Cards.push_back(Temp);
		}
	}
	CurrentPosition = Cards.size() - 1;

	std::random_device rd;
	std::mt19937 gen(rd());

	std::shuffle(Cards.begin(), Cards.end(), gen);
}

FDeck::~FDeck()
{
}

void FDeck::Check()
{
	for (auto Card : Cards)
	{
		Card->Show();
	}
}

FCard* FDeck::Draw()
{
	FCard* Temp = Cards[CurrentPosition];
	CurrentPosition--;

	return Temp;
}
