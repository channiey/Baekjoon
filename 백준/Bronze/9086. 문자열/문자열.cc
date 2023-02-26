#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const int iSize = 1024;
	int iCase = 0;
	char szTemp[iSize] = {};

	do {
		cin >> iCase;
	} while (1 > iCase || 10 < iCase);

	for (int i = 0; i < iCase; ++i)
	{
		cin >> szTemp;

		cout << szTemp[0] << szTemp[strlen(szTemp) - 1] << endl;
	}

	return 0;
}