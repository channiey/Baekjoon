#include <iostream>
using namespace std;

int Fibonacci(int iN);

int main(void)
{
	int iN(0);

	do
	{
		cin >> iN;
	} while (iN < 0 || 20 < iN);

	cout << Fibonacci(iN);

	return 0;
}

int Fibonacci(int iN)
{
	if (iN == 0)
		return 0;

	else if (iN == 1)
		return 1;

	else return Fibonacci(iN - 1) + Fibonacci(iN - 2);
}