#include "Boar.h"
#include <iostream>
using namespace std;

FBoar::FBoar()
{
	cout << "FBoar Constructor" << endl;
}

FBoar::~FBoar()
{
	cout << "FBoar Destructor" << endl;
}

void FBoar::Run()
{
}

void FBoar::Move()
{
	cout << "Boar" << ' ';
	FMonster::Move();
}
