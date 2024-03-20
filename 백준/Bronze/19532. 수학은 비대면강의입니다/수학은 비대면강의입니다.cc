#include <iostream>

int main()
{
	const int iMaxInput{ 6 };
	const int iMaxRange{ 999 };

	int arr[iMaxInput]{};

	for (size_t i = 0; i < iMaxInput; i++)
		std::cin >> arr[i];

	for (int x = -iMaxRange; x <= iMaxRange; x++)
	{
		for (int y = -iMaxRange; y <= iMaxRange; y++)
		{
			if (arr[0] * x + arr[1] * y == arr[2] &&
				arr[3] * x + arr[4] * y == arr[5])
			{
				std::cout << x << " " << y;
				break;
			}
		}
	}

	return 0;
}