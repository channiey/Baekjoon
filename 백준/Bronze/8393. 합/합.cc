#include <iostream>
using namespace std;

int main(void)
{
	int iN(0), iSum(0);

	do
	{
		cin >> iN;

	} while ((iN < 1) || (10000 < iN));

	for (int i = iN; i > 0; --i)
	{
		iSum += i;
	}

	cout << iSum;

	return 0;
}