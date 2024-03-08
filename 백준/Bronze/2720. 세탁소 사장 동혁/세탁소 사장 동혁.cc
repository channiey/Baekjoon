#include <iostream>

using namespace std;

int main()
{
	const int iTableNum = 4;
	const int iTable[iTableNum] = { 25, 10, 5, 1 };

	int iTestCase = 0;
	int iChange = 0;

	cin >> iTestCase;

	while (iTestCase--)
	{
		cin >> iChange;

		for (int i = 0; i < iTableNum; i++)
		{
			const int iOutPut = (0 == iChange) ? 0 : iChange / iTable[i];

			cout << iOutPut << " ";
			
			iChange %= iTable[i];
		}
	}

	return 0;
}
