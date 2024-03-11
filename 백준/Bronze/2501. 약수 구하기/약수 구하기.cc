#include <iostream>	

int main()
{
	int iN = 0, iK = 0, iIndex = 0, iResult = 0;

	std::cin >> iN >> iK;
	
	for (int i = 1; i <= iN; ++i)
	{
		if ((0 == iN % i) && (iK == ++iIndex))
		{
			iResult = i;
			break;
		}
	}
	
	std::cout << iResult;
	
	return 0;
}