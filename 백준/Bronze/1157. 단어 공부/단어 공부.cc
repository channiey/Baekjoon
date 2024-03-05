#include <iostream>

int main()
{
	const int iMaxSize = 26;
	int iCounts[iMaxSize] = {};

	while (true)
	{
		char chInput = std::cin.get();

		if ('\n' == chInput)
			break;

		if ('Z' < chInput)
			chInput -= 'a' - 'A';

		chInput -= 'A';

		if(iMaxSize > chInput)
			iCounts[chInput] += 1;
	}

	int iMaxValue = -1;
	int iMaxIndex = 0;
	
	for (int i = 0; i < iMaxSize; ++i)
	{
		if (iMaxValue < iCounts[i])
		{
			iMaxValue = iCounts[i];
			iMaxIndex = i;
		}
		else if (iMaxValue == iCounts[i])
		{
			iMaxIndex = -1;
		}
	}

	if (0 <= iMaxIndex)
		std::cout << (char)(iMaxIndex + 'A');
	else
		std::cout << '?';

	return 0;
}