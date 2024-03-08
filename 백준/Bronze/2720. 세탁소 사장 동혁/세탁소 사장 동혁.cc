#include <iostream>

int main()
{
	const int iTableNum = 4;
	const int iTable[iTableNum] = { 25, 10, 5, 1 };

	int iTestCase = 0;
	int iChange = 0;

	std::cin >> iTestCase;

	while (iTestCase--)
	{
		std::cin >> iChange;

		for (int i = 0; i < iTableNum; i++)
		{
			if (0 == iChange)
			{
				std::cout << 0 << " ";
				continue;
			}

			std::cout << iChange / iTable[i] << " ";

			iChange %= iTable[i];
		}
	}

	return 0;
}