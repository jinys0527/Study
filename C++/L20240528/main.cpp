#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Person.h"
#include <vector>

using namespace std;

int main()
{
	FDeck Deck;
	vector<FPerson*> Persons;
	Persons.push_back(new FDealer);
	Persons.push_back(new FPlayer);
	Persons.push_back(new FPlayer);
	Persons.push_back(new FPlayer);
	Persons.push_back(new FPlayer);
	Persons.push_back(new FPlayer);
	Persons.push_back(new FPlayer);

	for (int i = 0; i < Persons.size(); ++i)
	{
		Persons[i]->Draw(Deck.Draw());
		Persons[i]->Draw(Deck.Draw());
	}
	
	for (int i = 0; i < Persons.size(); ++i)
	{
		if (i == 0)
		{
			cout << "Dealer " << " Score : " << Persons[i]->Check() << endl;
		}
		else
		{
			cout << "Player " << i << " Score : " << Persons[i]->Check() 
				<< ((Persons[0]->Check() <= Persons[i]->Check()) ? " Win" : " Lost")
				<< endl;
		}
		Persons[i]->Show();
	}

	return 0;
}