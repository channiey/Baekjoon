#include <iostream>

int main()
{
	int iInput = 0;

	std::cin >> iInput;
	
	if (1 == iInput)
		return 0;

	for (int i = 2; i <= iInput;)
	{
		if (0 == iInput % i)
		{
			std::cout << i << std::endl;
			iInput /= i;
		}
		else
			++i;
	}

	return 0;
}