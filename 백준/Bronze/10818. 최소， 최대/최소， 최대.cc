#include <iostream>
using namespace std;

int main(void)
{
	int iN(0), iMax(0), iMin(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (1000000 < iN));

	int* arr = new int[iN];

	for (int i = 0; i < iN; ++i)
	{
		do
		{
			cin >> arr[i];
		} while ((arr[i] < -1000000) || (1000000 < arr[i]));

		if (i == 0)
		{
			iMax = arr[i];
			iMin = arr[i];
			continue;
		}

		iMax = (arr[i] > iMax) ? arr[i] : iMax;
		iMin = (arr[i] < iMin) ? arr[i] : iMin;
	}

	cout << iMin << " " << iMax;

	delete[] arr;

	return 0;
}