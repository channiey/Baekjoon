#include <iostream>
using namespace std;

int main (void)
{
	int iN(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (9 < iN));

	for (int i = 1; i <= 9; ++i)
	{
		cout << iN << " * " << i << " = " << iN * i << endl;
	}

	return 0;
}