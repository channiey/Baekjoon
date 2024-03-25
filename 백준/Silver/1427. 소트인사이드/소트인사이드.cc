#include <iostream>	

int main()
{
	int num{};
	int Bucket[10]{}; // Radix Sort

	std::cin >> num;
	
	while (0 < num)
	{
		const int digit = num % 10;

		num /= 10;

		++Bucket[digit];
	}

	
	for (int i = 9; i >= 0; i--)
	{
		while (Bucket[i])
		{
			std::cout << i;
			--Bucket[i];
		}
	}
	
	return 0;
}