#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int iLength = 0;
	char szTemp[1000] = {};

	cin >> szTemp;
	iLength = strlen(szTemp);

	for (int i = 0; i < iLength / 2 ; ++i)
	{
		if (szTemp[i] != szTemp[iLength - i - 1])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}