#include <iostream>
using namespace std;

int addNumbers(int number1, int number2)
{
	cout << "Entering function " << __func__ << endl;
	return number1 + number2;
}

int main()
{
	cout << addNumbers(3, 5)<<endl;

	return 0;
}