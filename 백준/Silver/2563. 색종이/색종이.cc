#include <iostream>

using namespace std;

int main(void)
{
	int iN = 0, iX = 0, iY = 0, iSum = 0;

	const int iBigSize = 100;
	const int iSmallSize = 10;
	int arr[iBigSize][iBigSize] = {};

	do {
		cin >> iN;
	} while (iBigSize < iN);

	for (int i = 0; i < iN; ++i)
	{
		cin >> iX >> iY;

		for (int j = iX; j < iX + iSmallSize; ++j)
		{
			for (int k = iY; k < iY + iSmallSize; ++k)
			{
				if (1 != arr[j][k])
					arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < iBigSize; ++i)
	{
		for (int j = 0; j < iBigSize; ++j)
		{
			if (1 == arr[i][j])
				iSum += 1;
		}
	}

	cout << iSum;

	return 0;
}