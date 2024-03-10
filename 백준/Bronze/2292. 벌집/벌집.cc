#include <iostream>	

int main()
{
	int iN = 0;

	std::cin >> iN;

	int iIndex = 1;
	int iSum = 1;

	while (true)
	{
		if (iN <= iSum)
			break;

		iSum += 6 * iIndex++;
	}
	
	std::cout << iIndex;

	return 0;
}