//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//int main()
//{
//	srand((unsigned int)time(nullptr));
//	int Size = 10;
//	int* Arr = new int[Size]();
//	int* NewArr = new int[Size+1]();
//	int Index = rand() % Size;
//	int Num;
//
//	for (int i = 0; i < Size; ++i)
//	{
//		Arr[i] = i + 1;
//	}
//	
//	cout << "���� : ";
//	for (int i = 0; i < Size; ++i)
//	{
//		cout << Arr[i] << ' ';
//	}
//	cout << endl;
//
//	cout << "�Է� : ";
//	cin >> Num;
//	cout << "�ԷµǴ� ��ġ : " << Index << endl;
//
//	for (int i = 0; i < Index; ++i)
//	{
//		NewArr[i] = Arr[i];
//	}
//	NewArr[Index] = Num;
//	for (int i = Index + 1; i < Size + 1; ++i)
//	{
//		NewArr[i] = Arr[i - 1];
//	}
//
//	delete[] Arr;
//	Arr = NewArr;
//	NewArr = nullptr;
//
//	cout << "�߰� �� : ";
//	for (int i = 0; i <= Size; ++i)
//	{
//		cout<<Arr[i]<<' ';
//	}
//
//	delete[] Arr;
//	Arr = nullptr;
//
//	return 0;
//}