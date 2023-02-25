#include <iostream>

using namespace std;

int main(void)
{
	int iN = 0, iMax = 0;
	do {
		cin >> iN;  
	} while (1 > iN || 100 < iN);

	iMax = iN * 2 - 1;

	for (int i = 0; i < iMax; ++i) 
	{
		for (int j = 0; j < iMax; ++j)
		{
			if (i <= iN - 1)
			{
				if ((j >= (iN - i - 1)) && (j <= (iN + i - 1)))
					cout << "*";
				else if (j < (iN - i - 1))
					cout << " ";
			}
			else if (i >= iN)
			{
				if (j >= ((iMax / 2) - (iMax - i - 1)) && (j <= ((iMax / 2) + (iMax - i - 1))))
					cout << "*";
				else if (j < ((iMax / 2) - (iMax - i - 1)))
					cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}