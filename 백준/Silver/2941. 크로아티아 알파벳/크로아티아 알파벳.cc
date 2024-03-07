#include <iostream>

int main()
{
	const int iMaxSize = 101;
	
	char szInput[iMaxSize] = {};
	int iCount = 0;

	std::cin >> szInput;
	
	for (int i = 0; i < iMaxSize; ++i)
	{
		if ('\0' == szInput[i])
			break;

		++iCount;

		// -, = 
		if ('=' == szInput[i] || '-' == szInput[i])
		{
			--iCount;

			if (1 < i && 'z' == szInput[i - 1] && 'd' == szInput[i - 2])
			{
				--iCount;	
			}
		}

		// lj, nj 
		if (0 < i && 'j' == szInput[i] && ('l' == szInput[i - 1] || 'n' == szInput[i - 1]))
			--iCount;
	}

	std::cout << iCount;

	return 0;
}