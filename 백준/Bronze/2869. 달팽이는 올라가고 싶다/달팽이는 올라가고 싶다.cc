#include <iostream>	

int main()
{
	int iAscend = 0, iDescend = 0, iHeight = 0;

	std::cin >> iAscend >> iDescend >> iHeight;
	
	std::cout << (iHeight - iDescend - 1) / (iAscend - iDescend) + 1;

	return 0;
}