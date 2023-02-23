#include <iostream>

using namespace std;

int main(void)
{
	const int iSize = 9;
	int iTemp = 0, iMax = 0, iX = 0, iY = 0;
	int arr[iSize][iSize] = {};

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			do {
				cin >> iTemp;
			} while (0 > iTemp || 100 < iTemp);

			if (iMax < iTemp)
			{
				iMax = iTemp;
				iX = i;
				iY = j;
			}
		}
	}

	cout << iMax << endl;
	cout << iX + 1 << " " << iY + 1 << endl;

	return 0;
}