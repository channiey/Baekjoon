#include <iostream>

int main()
{
	int iA = 0, iB = 0, iC = 0;

	while (true)
	{
		std::cin >> iA >> iB >> iC;
		
		if (0 == iA + iB + iC)
			break;
		if (iA >= iB + iC || iB >= iA + iC || iC >= iA + iB)
			std::cout << "Invalid\n";
		else if (iA == iB && iB == iC)
			std::cout << "Equilateral\n";
		else if (iA == iB || iB == iC || iC == iA)
			std::cout << "Isosceles\n";
		else
			std::cout << "Scalene\n";
	}
	
	return 0;
}
