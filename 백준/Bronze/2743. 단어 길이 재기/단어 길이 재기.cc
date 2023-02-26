#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const int iSize = 128;
	char szTemp[iSize] = {};

	cin >> szTemp;

	cout << strlen(szTemp);

	return 0;
}