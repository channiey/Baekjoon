#include <iostream>

int main()
{
	int iN{}, iSum{}, iGen{}, iCopy{};

	std::cin >> iN;

	for (int i = 0; i < iN; i++)
	{
		iCopy = i;

		while (0 < iCopy)
		{
			iSum += iCopy % 10;
			iCopy /= 10;
		}
		
		if (iN == i + iSum)
		{
			iGen = i;
			break;
		}

		iSum = 0;
	}

	std::cout << iGen;

	return 0;
}
