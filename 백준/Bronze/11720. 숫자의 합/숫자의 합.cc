#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
	int iN(0), iSum(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (100 < iN));

	int* arr = new int[iN];

	for (int i = 0; i < iN; ++i)
	{
		scanf("%1d", &arr[i]);
	}

	for (int i = 0; i < iN; ++i)
	{
		iSum += arr[i];
	}

	cout << iSum;

	return 0;
}