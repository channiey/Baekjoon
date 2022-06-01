#include <iostream>
using namespace std;

int main(void)
{
	int iN(0), iX(0);

	do
	{
		cin >> iN;
	} while (iN < 1);

	do
	{
		cin >> iX;
	} while (10000 < iX);

	int *arr = new int[iN];

	for (int i = 0; i < iN; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		if (iX > arr[i])
			cout << arr[i] << " ";
	}

	delete[] arr;

	return 0;
}