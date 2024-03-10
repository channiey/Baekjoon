#include <iostream>	

int main()
{
	int iInput = 0;
	std::cin >> iInput;

	int iSum = 1;
	int iIndex = 1;

	while (iSum < iInput)
		iSum += 6 * iIndex++;
	
	std::cout << iIndex;

	return 0;
}