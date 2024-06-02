#include "Monster.h"
#include <iostream>

using namespace std;

FMonster::FMonster()
{
	cout << "FMonster Constructor" << endl;
}

FMonster::~FMonster()
{
	cout << "FMonster Destructor" << endl;
}

void FMonster::Drop()
{
}

void FMonster::Move()
{
	cout << "Move" << endl;
}