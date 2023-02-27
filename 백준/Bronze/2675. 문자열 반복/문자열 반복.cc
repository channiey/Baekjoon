#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const int iSize = 32;
	int iCase = 0, iRepeat = 0, iLength = 0;
	char szTemp[iSize] = {};

	do
	{
		cin >> iCase;
	} while (1 > iCase || 1000 < iCase);

	for (int i = 0; i < iCase; ++i)
	{
		do
		{
			cin >> iRepeat;
		} while (1 > iRepeat || 8 < iRepeat);

		cin >> szTemp;

		iLength = strlen(szTemp);

		for (int j = 0; j < iLength; ++j)
		{
			for (int k = 0; k < iRepeat; ++k)
			{
				cout << szTemp[j];
			}
		}
		cout << endl;
	}

	return 0;
}