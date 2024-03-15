#include <iostream>	

int main()
{
	const int iMax = 10000;
	enum VALUE_TYPE {MIN_X, MIN_Y, MAX_X, MAX_Y, VALUE_TYPEEND };
	int iTable[VALUE_TYPEEND]{ iMax, iMax, -iMax, -iMax };

	int iN = 0, iX = 0, iY = 0;
	std::cin >> iN;

	while (iN--)
	{
		std::cin >> iX >> iY;

		if (iTable[MIN_X] > iX)
			iTable[MIN_X] = iX;

		if (iTable[MAX_X] < iX)
			iTable[MAX_X] = iX;

		if (iTable[MIN_Y] > iY)
			iTable[MIN_Y] = iY;

		if (iTable[MAX_Y] < iY)
			iTable[MAX_Y] = iY;
	}

	std::cout << (iTable[MAX_X] - iTable[MIN_X]) * (iTable[MAX_Y] - iTable[MIN_Y]);
	
	return 0;
}

