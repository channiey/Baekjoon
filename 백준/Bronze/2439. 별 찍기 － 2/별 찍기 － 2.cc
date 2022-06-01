#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN(0);

	do
	{
		cin >> iN;
	} while ((iN < 1) || (100 < iN));

	for (int i = iN; i > 0; --i) 
	{
		for (int j = 1; j <= iN; ++j) 
		{
			if (i <= j)
			{
				cout << "*";
			}
			else 
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}