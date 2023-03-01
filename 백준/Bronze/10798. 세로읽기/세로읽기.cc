#include <iostream>

using namespace std;

int main(void)
{
	const int iRow = 5, iCol = 15;
	char szTemp[iRow][iCol] = {};

	for (int i = 0; i < 5; ++i)
	{
		cin >> szTemp[i];
	}

	for (size_t i = 0; i < iCol; ++i)
	{
		for (size_t j = 0; j < iRow; ++j)
		{
			if ('\0' != szTemp[j][i])
				cout << szTemp[j][i];
		}
	}

	return 0;
}