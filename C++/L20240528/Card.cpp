#include "Card.h"
#include <iostream>
using namespace std;

FCard::FCard()
{
	Type = ECardType::None;
	Shape = "";
	Number = 0;
}

FCard::~FCard()
{
}

void FCard::SetShape(std::string NewShape)
{
	Shape = NewShape;
}

void FCard::SetNumber(int NewNumber)
{
	if (NewNumber >= 1 && NewNumber <= 13) 
	{
		Number = NewNumber;
	}
}

void FCard::SetType(ECardType NewCardType)
{
	Type = NewCardType;
}

void FCard::ShowNumber()
{
	switch (Number)
	{
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		cout << Number;
		break;
	}
}

int FCard::GetScore()
{
	if (Number > 10)
	{
		return 10;
	}

	return Number;
	return 0;
}

void FCard::Show()
{
	string CardType[4] = { 
		"¢À", "¢¼", "¢¾", "¡ß" 
	};

	cout << CardType[static_cast<int>(Type)] << " ";

	ShowNumber();

	cout << endl;
}
