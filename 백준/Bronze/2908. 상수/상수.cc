#include <iostream>

using namespace std;

int main(void)
{
	const int iSize = 4;
	char szNum1[iSize] = {}, szNum2[iSize] = {};

	cin >> szNum1 >> szNum2;

	for (int i = iSize - 2; i >= 0; --i)
	{
		if (szNum1[i] > szNum2[i])
		{
			for (int j = iSize - 2; j >= 0; --j)
			{
				cout << szNum1[j];
			}
			break;
		}
		else if(szNum1[i] < szNum2[i])
		{
			for (int j = iSize - 2; j >= 0; --j)
			{
				cout << szNum2[j];
			}
			break;
		}
	}

	return 0;
}