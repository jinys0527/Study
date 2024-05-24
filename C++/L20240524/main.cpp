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

	for (int i = 0; i < Range; ++i)
	{
		NewArr[i] = Arr[i];
	}

	cout << "입력 : ";
	cin >> Num;
	cout << "입력되는 위치 : " << Index << endl;
	for (int i = Range-1; i >= Index; --i)
	{
		int temp = NewArr[i];
		NewArr[i+1] = temp;
	}

	NewArr[Index] = Num;

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