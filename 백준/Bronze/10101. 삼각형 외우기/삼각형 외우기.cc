#include <iostream>

int main()
{
	int iA = 0, iB = 0, iC = 0;

	std::cin >> iA >> iB >> iC;

	if (180 == iA + iB + iC)
	{
		if ((iA == iB) && (iB == iC))
			std::cout << "Equilateral";
		else if (iA == iB || iB == iC || iC == iA)
			std::cout << "Isosceles";
		else
			std::cout << "Scalene";
	}
	else
	{
		std::cout << "Error";
	}
	return 0;
}


