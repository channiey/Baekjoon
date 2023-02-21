#include <iostream>

using namespace std;

int main(void)
{
	int iN = 0;

	do
	{
		cin >> iN;
	} while (4 > iN || 1000 < iN || (iN % 4) != 0);


	int iSize = (iN / 4) - 1;

	for (size_t i = 0; i < iSize; ++i)
	{
		cout << "long ";
	}
	cout << "long int " << endl;

	return 0;
}