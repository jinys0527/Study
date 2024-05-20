#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>

using namespace std;

int BeforeCard = 0;
int AfterCard = 0;
tuple<char, int, int> Com[2] = { {0, 0, 0}, };
tuple<char, int, int> Player[2] = { {0, 0, 0}, };
int ComTotal = 0;
int PlayerTotal = 0;
int ComShape = 0;
int PlayerShape = 0;
int ComDiff = 0;
int PlayerDiff = 0;

char CheckShape(int Card)
{
	char Shape = 0;
	Card--;
	if (Card / 13 == 0)
	{
		Shape = 'S';
	}
	else if (Card / 13 == 1)
	{
		Shape = 'C';
	}
	else if (Card / 13 == 2)
	{
		Shape = 'H';
	}
	else if (Card / 13 == 3)
	{
		Shape = 'D';
	}

	return Shape;
}

int CheckCard(int Card)
{
	int Div = (Card-1) / 13;
	Card -= 13 * Div;
	return Card;
}

void Calc(int Card, int Comp) 
{
	if (Comp == 0)
	{
		if (Card == 1 && ComTotal <= 10)
		{
			ComTotal += 11;
		}
		else if (Card > 10)
		{
			ComTotal += 10;
		}
		else if (Card <= 10)
		{
			ComTotal += Card;
		}
	}
	else if (Comp == 1)
	{
		if (Card == 1 && PlayerTotal <= 10)
		{
			PlayerTotal += 11;
		}
		else if (Card > 10)
		{
			PlayerTotal += 10;
		}
		else if (Card <= 10)
		{
			PlayerTotal += Card;
		}
	}
}

void Tick() 
{
	for (int i = 0; i < 2; ++i)
	{
		if (i != 0)
		{
			while (1) 
			{
				BeforeCard = (rand() % 52) + 1;
				if (BeforeCard != get<2>(Com[0]))
				{
					break;
				}
			}
		}
		else
		{
			BeforeCard = (rand() % 52) + 1;
		}
		ComShape = CheckShape(BeforeCard);
		AfterCard = CheckCard(BeforeCard);
		Com[i] = make_tuple(ComShape, AfterCard, BeforeCard);
		Calc(AfterCard, 0);

		if (i != 0)
		{
			while (1)
			{
				BeforeCard = (rand() % 52) + 1;
				if (BeforeCard != get<2>(Player[0]))
				{
					break;
				}
			}
		}
		else
		{
			BeforeCard = (rand() % 52) + 1;
		}
		PlayerShape = CheckShape(BeforeCard);
		AfterCard = CheckCard(BeforeCard);
		Player[i] = make_tuple(PlayerShape, AfterCard, BeforeCard);
		Calc(AfterCard, 1);
	}

	ComDiff = 21 - ComTotal;
	PlayerDiff = 21 - PlayerTotal;
}

void Render()
{
	cout << "Com : ";
	for (int i = 0; i < 2; i++)
	{
		cout << get<0>(Com[i]) << ' ';
		if (get<1>(Com[i]) == 1) 
		{
			cout << "A ";
		}
		else if (get<1>(Com[i]) <= 10)
		{
			cout << get<1>(Com[i]) << ' ';
		}
		else if (get<1>(Com[i]) == 11)
		{
			cout << "J ";
		}
		else if (get<1>(Com[i]) == 12)
		{
			cout << "Q ";
		}
		else if (get<1>(Com[i]) == 13)
		{
			cout << "K ";
		}
	}
	cout << endl;
	cout << "ComTotal : " << ComTotal << endl;
	cout << "ComDiff : " << ComDiff << endl << endl;

	cout << "Player : ";
	for (int i = 0; i < 2; i++)
	{
		cout << get<0>(Player[i]) << ' ';
		if (get<1>(Player[i]) == 1)
		{
			cout << "A ";
		}
		else if (get<1>(Player[i]) <= 10)
		{
			cout << get<1>(Player[i]) << ' ';
		}
		else if (get<1>(Player[i]) == 11)
		{
			cout << "J ";
		}
		else if (get<1>(Player[i]) == 12)
		{
			cout << "Q ";
		}
		else if (get<1>(Player[i]) == 13)
		{
			cout << "K ";
		}
	}
	cout << endl;
	cout << "PlayerTotal : " << PlayerTotal << endl;
	cout << "PlayerDiff : " << PlayerDiff << endl << endl;

	if (ComDiff > PlayerDiff)
	{
		cout << "Player Win" << endl;
	}
	else if (ComDiff == PlayerDiff)
	{
		cout << "Draw" << endl;
	}
	else if (ComDiff < PlayerDiff)
	{
		cout << "Com Win" << endl;
	}
	cout << endl;
}

int main()
{
	srand((unsigned int)time(nullptr));

	Tick();
	Render();
	 
	return 0;
}