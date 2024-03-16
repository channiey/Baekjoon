#include <iostream>

int main()
{
	int iA = 0, iB = 0, iC = 0;

	std::cin >> iA >> iB >> iC;

	if (iA >= iB + iC)
	{
		iA = iB + iC - 1;
	}
	else if (iB >= iA + iC)
	{
		iB = iA + iC - 1;
	}
	else if (iC >= iA + iB)
	{
		iC = iA + iB - 1;
	}
	
	std::cout << iA + iB + iC;

	return 0;
}