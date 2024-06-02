#include "Slime.h"
#include <iostream>
using namespace std;

FSlime::FSlime()
{
	cout << "FSlime Constructor" << endl;
}

FSlime::~FSlime()
{
	cout << "FSlime Destructor" << endl;
}

void FSlime::Slide()
{
}

void FSlime::Move()
{
	cout << "Slime" << ' ';
	FMonster::Move();
}
