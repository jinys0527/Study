#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	srand((unsigned int)time(nullptr));
	int Range = 10;
	int* Arr = new int[Range]();
	int* NewArr = new int[Range+1]();
	int Index = rand() % Range;
	int Num;

	for (int i = 0; i < Range; ++i)
	{
		Arr[i] = i + 1;
	}
	
	cout << "기존 : ";
	for (int i = 0; i < Range; ++i)
	{
		cout << Arr[i] << ' ';
	}
	cout << endl;

	cout << "입력 : ";
	cin >> Num;
	cout << "입력되는 위치 : " << Index << endl;

	for (int i = 0; i < Index; ++i)
	{
		NewArr[i] = Arr[i];
	}
	NewArr[Index] = Num;
	for (int i = Index + 1; i < Range + 1; ++i)
	{
		NewArr[i] = Arr[i - 1];
	}

	delete[] Arr;
	Arr = NewArr;
	NewArr = nullptr;

	cout << "추가 후 : ";
	for (int i = 0; i <= Range; ++i)
	{
		cout<<Arr[i]<<' ';
	}

	delete[] Arr;
	Arr = nullptr;

	return 0;
}