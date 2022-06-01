#include <iostream>
using namespace std;

int main(void)
{
	int iN(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (100 < iN));
	
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}